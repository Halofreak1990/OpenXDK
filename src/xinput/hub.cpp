/******************************************************************************/
/*																              */
/*  File: hub.cpp                                                             */
/*  bkenwright@xbdev.net  -  www.xbdev.net                                    */
/*                                                                            */
/******************************************************************************/

#include "hub.h"
#include "misc.h"



extern __u32 eds[176 + 0x100 + 0x100]; // ohci.cpp
extern __u32 EDA;
extern s_Endpointdescripor * ED;



//#define USB_DEBUG
//#define USB_DEBUG_ERROR


/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


//   Offset	Field		Size	Value		Desc
//   0		bmRequestType	1	Bitmap		D7:	Direction
//  							0 = Host-to-device
//  							1 = Device-to-host
//  							D6..5:	Type
//  							0 = Standard
//  							1 = Class
//  							2 = Vendor
//  							3 = Reserved
//  							D4..0:	Recipient
//  							0 = Device
//  							1 = Interface
//  							2 = Endpoint
//  							3 = Other
//  							4..31 = Reserved
//   1		bRequest	1	Value		Specific request (9-3)
//   2		wValue		2	Value		Varies
//   4		wIndex		2	Index/Offset	Varies
//   6		wLength		2	Count		Bytes for data
/*
struct devrequest
{
	unsigned char  requesttype; // 1 byte
	unsigned char  request;     // 1 byte
	unsigned short value;       // 2 bytes
	unsigned short index;       // 2 bytes
	unsigned short length;      // 2 bytes
};                              //   Total = 8 bytes
*/



int get_control_msg(ohci_t * ohci, 
					__u8 Addr,
					__u8 request,     // 0x06
					__u8 requesttype, // 0x80
					__u16 value,
					__u16 index,
					__u16 size,
					__u8 *data )
{

	// First, lets desribe what type of message this is!
	devrequest cmd;
	

	cmd.requesttype	= requesttype; //0x80;
	cmd.request		= request;     //0x06;
	cmd.value       = value; //(0x29<<8);
	cmd.index		= index;
	cmd.length		= ((__u16) size);


	xMmLockUnlockBufferPages( (__u32)&cmd, 0x8, 0);
	__u32 real_pcmd = xMmGetPhysicalAddress( (__u32)&cmd);


	__u8 Descriptors[256] = {0};
	xMmLockUnlockBufferPages( (__u32)Descriptors, 256, 0 );
	__u32 real_pDescriptors = xMmGetPhysicalAddress( (__u32)Descriptors );


	//__u32 uTD = (__u32)pTD;
	//uTD += (__u32)0x10;
	//uTD &= 0xfffffff0;

	s_Transferdescriptor *TD;
	TD = (s_Transferdescriptor *)(((__u32 *)ED) + 20);
	__u32 TDA = EDA + 80;
	__u32 realTDA = xMmGetPhysicalAddress( (__u32)TDA );



////////////////////////////////////////////////////////////////////////
//   --Transfer Descriptor TD--
//   Offset	Field		Size	Value		Desc
//   0                  4       0..17       reserved
//                              
//      						18          R  - bufferRounding
//								19..20      DP - Direction/PID
//								                 00b SETUP
//												 01b OUT
//												 10b IN
//												 11b reserved
//								21..23      DI - DelayInterrupt
//	                            24..25      T  - DataToggle
//								26..27      EC - ErrorCount
//								28..31      CC - ConditionCode
//  4                   4                   CurrentBufferPoinnter (CBP)
//	8                   4       0..3        Zero
//	                            4..31       Next TD (NextTD)
// 12                   4                   Buffer End (BE)
//                                             
//(Total Size 16 bytes or 4 dwords)
//
////////////////////////////////////////////////////////////////////////

	__u32 v_format  = 0;
	v_format        |= (0xE<<28); // 1110b - CC
	v_format        |= (0x0<<26); // 00b   - EC
	v_format        |= (0x2<<24); // 10b   - T
	// E2
	v_format        |= (0x0<<21); // 000b  - DelayInterrupt
	v_format        |= (0x0<<19); // 00b   - DR (SETUP)
	v_format        |= (0x0<<18); // 0b    - bufferRound (NO)
	v_format        |= (0x0<<16); // 00b   - reserved
	// 00
	v_format        |= 0x50CA;    // reserved
	// 50CA


	TD[0].Format	= 0xE20050CA;					// Get Descriptor
	TD[0].Buffer	= real_pcmd;  
	TD[0].NextTD	= realTDA + 16; 
	TD[0].BufferEnd	= real_pcmd + 7; 		

	TD[1].Format	= 0xE31450CB;					// Receive Start of Descriptor
	TD[1].Buffer	= real_pDescriptors; 
	TD[1].NextTD	= realTDA + 32;
	TD[1].BufferEnd = real_pDescriptors + 7;


	//-------------------------------------------------------------

	TD[2].Format	= 0xE21450CC;					// Receive Rest of Descriptor
	TD[2].Buffer	= real_pDescriptors + 8;
	TD[2].NextTD	= realTDA + 48;
	TD[2].BufferEnd	= 0;

	TD[3].Format	= 0xE30050CD;					// Queue END
	TD[3].Buffer	= 0;
	TD[3].NextTD	= 0;
	TD[3].BufferEnd	= 0;

////////////////////////////////////////////////////////////////////////
//   --EndPoint Descriptor ED--
//   Offset	Field		Size	Value		Desc
//   0                  4       Bitmap           
//	                            0..6        FA - Function Address
//	 							
//		                        7..10       EN - EndpointNumber
//								11..12      D  - Direction
//								                 00b GetDir From TD
//												 01b OUT
//												 10b IN
//												 11b GetDir From TD
//								13          S  - Speed (Full Speed=0)
//								14          K  - sKip
//								15          F  - Format
//								                 0 - Control/Bulk/Int
//												 1 - Isochronous
//	                            16..26      MPS  MaximumPacketSize
//							    27..31      reserved
//	4                   4       Bitmap
//	                            0..3        Zero Aligment
//								4..31       TD Queue Tail Pointer (TailP)
//	8                   4       Bitmap
//	                            0           H  - Halted
//								1           C  - toggleCarry
//								2..3        reserved
//								4..31       TD Queue Head Pointer (HeadP)
//	12                  4       Bitmap
//	                            0..3        Zero Aligment
//								4..31       Next Endpoint Descriptor (NextED)
//
//(Total Size 16 bytes or 4 dwords)
//
////////////////////////////////////////////////////////////////////////

	ED[1].Headptr = realTDA;
	ED[1].Tailptr = realTDA + 32;
	ED[1].Format  &= 0xFFFFFF00;                     // Clear old address
	ED[1].Format  += Addr;                           // Insert new address


	TD[1].BufferEnd = real_pDescriptors + size - 1;


	ohci->regs->cmdstatus  |= 2;			         // CommandStatus
	ohci->regs->control	   = 0x90;		             // set CLE
	ohci->regs->intrstatus = ohci->regs->intrstatus; // clear all Interruptflags


#ifdef USB_DEBUG
	// wait for execution
	dbg("waiting for execution\n");
#endif //USB_DEBUG
	do
	{

	}while(  (ohci->regs->intrstatus & 2)== 0 );

	xSleep(10);

	// ERRORS?
	ohci_hcca *hcca = (ohci_hcca*)ohci->hcca;		// HCCA
	hcca->done_head &= 0xfffffffe;					// DoneHead in HCCA

	if( (hcca->done_head>>28) !=0 )
	{
#ifdef USB_DEBUG
		dbg("\nError Occured\n");
#endif //USB_DEBUG
		return 1;
	}

	//------------------------------------------------------------------

	// Where all done and finished now, so we set our ED's to our
	// Queue END where they behave and wait.
	ED[1].Headptr = realTDA + 48;
	ED[1].Tailptr = realTDA + 64;

	if( Descriptors[0] < size) size = Descriptors[0];


	xSleep(10);

	xmemcpy( data, Descriptors, size);

#ifdef USB_DEBUG
	// Few debug lines
	#define  OHCI_TD_GET_EC(x)      (((x) >> 26) & 3) 
	#define  OHCI_TD_GET_CC(x)      ((x) >> 28) 

	__u32 ErrorCount     = OHCI_TD_GET_EC( TD[0].Format );
	__u32 ConditionCode  = OHCI_TD_GET_CC( TD[0].Format );

	sprintf(buf, "TD[0]:ErrorCount: %d\n", ErrorCount); dbg(buf);
	sprintf(buf, "TD[0]:ConditionCode: %d\n", ConditionCode); dbg(buf);

	ErrorCount     = OHCI_TD_GET_EC( TD[1].Format );
	ConditionCode  = OHCI_TD_GET_CC( TD[1].Format );

	sprintf(buf, "TD[1]:ErrorCount: %d\n", ErrorCount); dbg(buf);
	sprintf(buf, "TD[1]:ConditionCode: %d\n", ConditionCode); dbg(buf);
#endif //USB_DEBUG

	return 0;
}// End of get_control_msg(..)


/******************************************************************************/







/******************************************************************************/

int set_control_msg(ohci_t * ohci, 
					__u8 Addr,
					__u8 request,     // 0x06
					__u8 requesttype, // 0x80
					__u16 value,
					__u16 index,
					__u16  size,
					__u8 *data )
{
		// First, lets desribe what type of message this is!
	devrequest cmd;
	

	cmd.requesttype	= requesttype; //0x80;
	cmd.request		= request;     //0x06;
	cmd.value       = value;      //(0x29<<8);
	cmd.index		= index;
	cmd.length		= ((__u16) size);


	xMmLockUnlockBufferPages( (__u32)&cmd, 0x8, 0);
	__u32 real_pcmd = xMmGetPhysicalAddress( (__u32)&cmd);


	s_Transferdescriptor *TD;


	TD = (s_Transferdescriptor *) (((__u32 *)ED) +20 );
	__u32 TDA = EDA + 80;

	__u32 realTDA = xMmGetPhysicalAddress( (__u32)TDA );

	TD[0].Format	= 0xE20050C7;				     // Set Configuration
	TD[0].Buffer	= real_pcmd;
	TD[0].NextTD	= realTDA + 16;
	TD[0].BufferEnd	= real_pcmd + 7;
	TD[1].Format	= 0xE30050C8;
	TD[1].Buffer	= 0;
	TD[1].NextTD	= 0;
	TD[1].BufferEnd	= 0;
	
	ED[1].Headptr	= realTDA;
	ED[1].Tailptr	= realTDA + 16;
	ED[1].Format	&= 0xFFFFFF00;
	ED[1].Format	+= Addr;


	// set CLF
	ohci->regs->cmdstatus |= 2;			             // CommandStatus

	ohci->regs->control	 = 0x90;		             // set CLE

	ohci->regs->intrstatus = ohci->regs->intrstatus; // clear all Interruptflags

#ifdef USB_DEBUG_ERROR
	// wait for execution
	dbg("waiting for execution\n");
#endif //USB_DEBUG



	//xSleep(250);

	do
	{

	}while(  (ohci->regs->intrstatus & 2)== 0 );

	xSleep(10);


	// ERRORS?
	ohci_hcca *hcca = (ohci_hcca*)ohci->hcca;        // HCCA
	hcca->done_head &= 0xfffffffe;					 // DoneHead in HCCA

	if( (hcca->done_head>>28) !=0 )
	{
#ifdef USB_DEBUG
		dbg("\nError Occured in set_control_msg(..)\n");
#endif //USB_DEBUG
		return 1;
	}

	return 0;

}// End of set_control_msg(..)






/******************************************************************************/

/*
int usb_get_device_descriptor(ohci_t * ohci, __u8 Addr, int size, void *buf)
{
	__u8 type  = USB_DT_DEVICE;
	__u8 index = 0;

	int ret = get_control_msg(ohci, Addr,
		            USB_REQ_GET_DESCRIPTOR, USB_DIR_IN,
					(type << 8) + index, 0, size, (__u8*)buf );
	return ret;

}// End of usb_get_device_descriptor(..)
*/

/******************************************************************************/
/*
int usb_get_hub_descriptor(ohci_t * ohci, __u8 Addr, int size, void *buf)
{

	int ret = get_control_msg(ohci, Addr,
		            USB_REQ_GET_DESCRIPTOR, USB_DIR_IN | USB_RT_HUB,
					(USB_DT_HUB << 8), 0, size, (__u8*)buf );

	return ret;
}// End of usb_get_hub_descriptor(..)
*/
/******************************************************************************/



/******************************************************************************/


int usb_set_configuration(ohci_t * ohci, __u8 Addr, int configuration)
{
	int ret=0;

	ret = set_control_msg(ohci, Addr,
	    USB_REQ_SET_CONFIGURATION, 0, configuration, 0, 0, NULL);


    if( ret < 0 )
		return ret;

	return 0;
}// End of usb_set_configuration(..)


/******************************************************************************/


void DebugHubDescriptor( usb_hub_descriptor * pDes )
{
#ifdef USB_DEBUG
	sprintf(buf, "\n@HUB Descriptor@\n");	dbg(buf);

	sprintf(buf, "HubDes.bLength: 0x%02X\n",		  pDes->bLength );				dbg(buf);
	sprintf(buf, "HubDes.bDescriptorType: 0x%02X\n",  pDes->bDescriptorType );	    dbg(buf);
	sprintf(buf, "HubDes.bNbrPorts: 0x%02X\n",        pDes->bNbrPorts );			dbg(buf);
	sprintf(buf, "HubDes.wHubCharacteristics: 0x%02X\n",pDes->wHubCharacteristics);	dbg(buf);
	sprintf(buf, "HubDes.bPwrOn2PwrGood: 0x%02X\n",   pDes->bPwrOn2PwrGood );		dbg(buf);
	sprintf(buf, "HubDes.bHubContrCurrent: 0x%02X\n", pDes->bHubContrCurrent );		dbg(buf);
	sprintf(buf, "HubDes.DeviceRemovable: 0x%02X\n", pDes->DeviceRemovable );		dbg(buf);
	sprintf(buf, "HubDes.PortPowerCtrlMask: 0x%02X\n", pDes->PortPowerCtrlMask );		dbg(buf);
#endif //USB_DEBUG

}// End of DebugHubDescriptor



#define  UDESC_HUB              0x29


/******************************************************************************/

//#define USETW2(w,h,l) (((__u8*)(w))[0] = (__u8)(l), ((__u8*)(w))[1] = (__u8)(h))
__u16 USETW2(__u16 v)
{
	__u16 a = 0;;
	a |= (0xff00&(v<<8));
	a |= (0x00ff&(v>>8));

	return a;
}

#define UGETW(w) (*(__u16 *)(w))
#define USETW(w,v) (*(__u16 *)(w) = (v))
#define UGETDW(w) (*(__u32 *)(w))
#define USETDW(w,v) (*(__u32 *)(w) = (v))



int usbd_do_request(usbd_device * dev, devrequest *req, void *data)
{
	return  get_control_msg(dev->p_ohci, 
							dev->address,
							req->request,
							req->requesttype,
							req->value,
							req->index,
							req->length, // e.g. size buffer
							(__u8*)data );

}// End of usbd_do_request(..)


int usbd_get_hub_descriptor(usbd_device * dev, void * data)
{
         /* Get hub descriptor. */
		 devrequest req  = {0};
         req.requesttype = UT_READ_CLASS_DEVICE;
         req.request     = UR_GET_DESCRIPTOR;
         req.value       = USETW2(USB_DT_HUB);
         req.index       = 0;
         req.length      = USB_HUB_DESCRIPTOR_SIZE; 
         
		 return usbd_do_request(dev, &req, data);
}


int usbd_set_port_feature(usbd_device * dev, int port, int sel)
{
         devrequest req;
 
         req.requesttype = UT_WRITE_CLASS_OTHER;
         req.request     = UR_SET_FEATURE;
         req.value       = sel;
         req.index       = port;
         req.length      = 0;
         return  usbd_do_request(dev, &req, 0);
}



#define UHD_NOT_REMOV(desc, i) \
     (((desc)->DeviceRemovable[(i)/8] >> ((i) % 8)) & 1)

#define UHF_PORT_POWER          8


int usbd_get_port_status(usbd_device * dev, int port, void *data)
{

	devrequest req;

	req.requesttype = UT_READ_CLASS_OTHER;
	req.request      = UR_GET_STATUS;
	req.value         = 0;
	req.index         = port;
	req.length        = sizeof(usb_port_status );
	return usbd_do_request(dev, &req, data);

}// End of usb_get_port_status(..)


#define UPS_C_CONNECT_STATUS            0x0001
#define UPS_C_PORT_ENABLED              0x0002
#define UPS_C_SUSPEND                   0x0004
#define UPS_C_OVERCURRENT_INDICATOR     0x0008
#define UPS_C_PORT_RESET                0x0010


/* BUG~~~~~ this functino needs to be looked at...usb_do_req..should be set*/
int usbd_clear_port_feature(usbd_device * dev, int port, int sel)
{
	devrequest req;
	 
	req.requesttype = UT_WRITE_CLASS_OTHER;
	req.request     = UR_CLEAR_FEATURE;
	req.value       = sel;
	req.index       = port;
	req.length      = 0;
	return usbd_do_request(dev, &req, 0);
}

/* Hub features */
#define UHF_C_HUB_LOCAL_POWER   0
#define UHF_C_HUB_OVER_CURRENT  1
#define UHF_PORT_CONNECTION     0
#define UHF_PORT_ENABLE         1
#define UHF_PORT_SUSPEND        2
#define UHF_PORT_OVER_CURRENT   3
#define UHF_PORT_RESET          4
#define UHF_PORT_POWER          8
#define UHF_PORT_LOW_SPEED      9
#define UHF_C_PORT_CONNECTION   16
#define UHF_C_PORT_ENABLE       17
#define UHF_C_PORT_SUSPEND      18
#define UHF_C_PORT_OVER_CURRENT 19
#define UHF_C_PORT_RESET        20
#define UHF_PORT_TEST           21
#define UHF_PORT_INDICATOR      22


int usbd_reset_port(usbd_device * dev, int port, usb_port_status *ps)
{
	devrequest req;

	int n;

	req.requesttype = UT_WRITE_CLASS_OTHER;
	req.request     = UR_SET_FEATURE;
	req.value      = UHF_PORT_RESET;
	req.index      = port;
	req.length     = 0;
	usbd_do_request(dev, &req, 0);

#ifdef USB_DEBUG
	sprintf(buf, "usbd_reset_port: port %d reset done\n",port); dbg(buf);
#endif //USB_DEBUG

	n = 10;
	do {
		/* Wait for device to recover from reset. */
		#define USB_PORT_RESET_DELAY    50
		xSleep(USB_PORT_RESET_DELAY);

		usbd_get_port_status(dev, port, ps);

		/* If the device disappeared, just give up. */
		#define UPS_CURRENT_CONNECT_STATUS      0x0001
		if (!((ps->wPortStatus) & UPS_CURRENT_CONNECT_STATUS))
		{
#ifdef USB_DEBUG
			dbg("The device disappeared so we give up reset!\n");
#endif //USB_DEBUG
				return 0;
		}
	} while ( ((ps->wPortChange) & UPS_C_PORT_RESET) == 0 &&  (--n > 0) );

	if (n == 0)
	{
#ifdef USB_DEBUG
		dbg("Timout error in 'usbd_reset_port(..)'\n");
#endif //USB_DEBUG
		return 0;
	}

	usbd_clear_port_feature(dev, port, UHF_C_PORT_RESET);

#ifdef USB_DEBUG
	dbg("usbd_reset_port: clear port\n");
#endif //USB_DEBUG

	/* Wait for the device to recover from reset. */
	#define USB_PORT_RESET_RECOVERY 250
	xSleep(USB_PORT_RESET_RECOVERY);

	return 1;
}


//#define USETW2XXX(w,h,l) (((__u8*)(w))[0] = (__u8)(l), ((__u8*)(w))[1] = (__u8)(h))

int usbd_get_desc(usbd_device * dev, int type, int index, int len, void *desc)
{
	devrequest req = {0};

#ifdef USB_DEBUG
	sprintf( buf, "usbd_get_desc: type=%d, index=%d, len=%d\n",type, index, len);
	dbg(buf);
#endif //USB_DEBUG

 
	req.requesttype = UT_READ_DEVICE;
	req.request     = UR_GET_DESCRIPTOR;
	//USETW2XXX(req.value, type, index);
	req.value = 0;
	req.value |= (0x00ff & index);
	req.value |= (0xff00 & (type<<8));

	req.index       = 0;
	req.length      = len;

	return (usbd_do_request(dev, &req, desc));
}


int usbd_set_address(usbd_device * dev, int addr)
{
	devrequest req = {0};

	req.requesttype = UT_WRITE_DEVICE;
	req.request      = UR_SET_ADDRESS;
	req.value        = addr;
	req.index        = 0;
	req.length       = 0;
	return usbd_do_request(dev, &req, 0);
}


int usbd_set_config(usbd_device * dev, int conf)
{
	devrequest req;
 
	req.requesttype = UT_WRITE_DEVICE;
	req.request     = UR_SET_CONFIG;
	req.value       = conf;
	req.index       = 0;
	req.length      = 0;
	return usbd_do_request(dev, &req, 0);
}



int usbd_set_config_index(usbd_device * dev, int index, int msg /*1*/)
{

	s_USB_Configurationdescriptor cd, *cdp;
	__u8 buffer[256];
	cdp = (s_USB_Configurationdescriptor*)buffer;

	#define  UDESC_CONFIG           0x02
	#define USB_CONFIG_DESCRIPTOR_SIZE 9


	/* Get the short descriptor. */
	usbd_get_desc(dev, UDESC_CONFIG, index, USB_CONFIG_DESCRIPTOR_SIZE, &cd);


	/* Get the full descriptor. */
	usbd_get_desc(dev, UDESC_CONFIG, index, cd.TotalLength, buffer);

	/* Set the actual configuration value. */
#ifdef USB_DEBUG
	sprintf(buf, "usbd_set_config_index: set config %d\n",cdp->ConfigValue);
	dbg(buf);
#endif //USB_DEBUG
	usbd_set_config(dev, cdp->ConfigValue);


	return 1;
}


/*
* Called when a new device has been put in the powered state,
* but not yet in the addressed state.
* Get initial descriptor, set the address, get full descriptor,
* and attach a driver.
*/

extern __u8 found;

int usbd_new_device(usbd_device * parent, int b, int depth,
                   int speed, int port, usb_port_status * ps)
{
#ifdef USB_DEBUG
	sprintf(buf, "usbd_new_device port=%d depth=%d speed=%d\n",port, depth, speed);
	dbg(buf);
#endif //USB_DEBUG

	usbd_device dev;
	dev.p_ohci  = parent->p_ohci;
	dev.address = 0;

	found++;
	int addr = found;

	s_USB_Devicedescriptor dd = {0};
	/* Try a few times in case the device is slow (i.e. outside specs.) */
	//for (int i = 0; i < 15; i++) 
	//{
		#define USB_MAX_IPACKET         8 /* maximum size of the initial packet */


		/* Get the first 8 bytes of the device descriptor. */
		usbd_get_desc(&dev, UDESC_DEVICE, 0, USB_MAX_IPACKET, &dd);

		xSleep(100);

	//	if ((i & 3) == 3)
	//		usbd_reset_port(parent, port, ps);

	//}


	/* Set the address */
#ifdef USB_DEBUG
	sprintf(buf, "****usbd_new_device: adding unit addr= %d *****\n", addr ); dbg(buf);
#endif //USB_DEBUG

	usbd_set_address(&dev, addr);
	
#ifdef USB_DEBUG
	sprintf(buf, "usbd_new_device: setting device address=%d\n", addr); dbg(buf);
#endif //USB_DEBUG


	/* Allow device time to set new address */
	#define USB_SET_ADDRESS_SETTLE  10  /* ms */
	xSleep(USB_SET_ADDRESS_SETTLE);

	dev.address = addr;

	/* Get full descriptor */
	#define USB_DEVICE_DESCRIPTOR_SIZE 18
	usbd_get_desc(&dev, UDESC_DEVICE, 0, USB_DEVICE_DESCRIPTOR_SIZE, &dd);

#ifdef USB_DEBUG
	DebugDescriptor( &dd );
#endif //USB_DEBUG



	for (int confi = 0; confi < dd.ConfigNumber; confi++) 
	{
#ifdef USB_DEBUG
		sprintf(buf,"usbd_probe_and_attach: trying config idx=%d\n",confi); dbg(buf);
#endif //USB_DEBUG

		usbd_set_config_index(&dev, confi, 1);

		//usb_set_configuration(dev.p_ohci, dev.address, confi);

	}

	xSleep(40);


	do_hub_work(&dev);

	return 1;
}



int do_hub_work(usbd_device * dev)
{

	__u8 buffer[256] = {0};
	usb_hub_descriptor hubdesc = {0};

	int port, nremov=0;


	/* Get hub descriptor. */
#ifdef USB_DEBUG
	dbg("usb_init_hub: getting hub descriptor\n\n");
#endif //USB_DEBUG
	usbd_get_hub_descriptor(dev, (void*)&hubdesc);

#ifdef USB_DEBUG
	DebugHubDescriptor( (usb_hub_descriptor * )&hubdesc );
	dbg("\n\n");
#endif //USB_DEBUG


	int nports = hubdesc.bNbrPorts;


	//for (nremov = 0, port = 1; port <= nports; port++)
	//	if (!UHD_NOT_REMOV((&hubdesc), port))
	//		nremov++;


	for (port = 1; port <= nports; port++) 
	{
                 /* Turn the power on. */
                 usbd_set_port_feature(dev, port, UHF_PORT_POWER);
#ifdef USB_DEBUG
                 sprintf(buf, "usb_init_port: turn on port %d power\n", port); dbg(buf);
#endif //USB_DEBUG

                 /* Wait for stable power. */
                 xSleep(50);
	}// End for loop

#ifdef USB_DEBUG
	dbg("\n\n");
#endif //USB_DEBUG

	for (port = 1; port <= nports; port++) 
	{
		usb_port_status ps = {0};

		usbd_get_port_status(dev, port, &ps);

		__u16 status = ps.wPortStatus;
		__u16 change = ps.wPortChange;

#ifdef USB_DEBUG
		sprintf(buf, "uhub_explore: port %d status 0x%04x 0x%04x\n",port, status, change);
		dbg(buf);
#endif //USB_DEBUG
	}


	// Wahooo...we have results!....we know whats plugged into our xbox
	// first simple step!
	/*
	Well if you've made it here...XBOX GAMEPAD...well this is what we notice...
	we can detect which gamepads are plugged in
	gamepad_1   ->   port 3
	gamepad_2   ->   port 4
	gamepad_3   ->   port 1
	gamepad_4   ->   port 2
	*/

#ifdef USB_DEBUG
	dbg("\n\n");
#endif //USB_DEBUG

	for(port = 1; port <= nports; port++)
	{

		usb_port_status ps = {0};

		usbd_get_port_status(dev, port, &ps);

		__u16 status = ps.wPortStatus;
		__u16 change = ps.wPortChange;

#ifdef USB_DEBUG
		sprintf(buf, "uhub_explore: port %d status 0x%04x 0x%04x\n",port, status, change);
		dbg(buf);
#endif //USB_DEBUG

#ifdef USB_DEBUG
		if (change & UPS_C_PORT_ENABLED) 
			dbg("uhub_explore: C_PORT_ENABLED\n");
#endif //USB_DEBUG


		/*
		if (!(change & UPS_C_CONNECT_STATUS)) 
		{
			sprintf(buf, "uhub_explore: port=%d !C_CONNECT_STATUS\n", port); dbg(buf);

			#define UPS_CURRENT_CONNECT_STATUS      0x0001
			if( (status & UPS_CURRENT_CONNECT_STATUS) )
			{
				sprintf(buf, "\t\tconnected device\n"); dbg(buf);
			}

			//No status change, just do recursive explore
			continue;
		}
		*/

		// Not exactly correct...no change in status...but...just stay with me 
		// on this

		/* We have a connect status change, handle it. */
#ifdef USB_DEBUG
		sprintf(buf, "uhub_explore: status change hub=%d port=%d\n", dev->address, port);
		dbg(buf);
#endif //USB_DEBUG


		usbd_clear_port_feature(dev, port, UHF_C_PORT_CONNECTION);
		/*usbd_clear_port_feature(dev, port, UHF_C_PORT_ENABLE);*/
		/*
		* If there is already a device on the port the change status
		* must mean that is has disconnected.  Looking at the
		* current connect status is not enough to figure this out
		* since a new unit may have been connected before we handle
		* the disconnect.
		*/

		#define UPS_CURRENT_CONNECT_STATUS      0x0001

		if (!(status & UPS_CURRENT_CONNECT_STATUS)) 
		{
			/* Nothing connected, just ignore it. */
#ifdef USB_DEBUG
			sprintf(buf, "uhub_explore: port=%d !CURRENT_CONNECT_STATUS\n", port); dbg(buf);
#endif //USB_DEBUG
			continue;
		}


		/* Connected */

#ifdef USB_DEBUG
		#define UPS_PORT_POWER                  0x0100
		if (!(status & UPS_PORT_POWER))
		{
			sprintf(buf, "<>strange, connected port %d has no power\n",port); dbg(buf);
		}
#endif //USB_DEBUG

		/* Wait for maximum device power up time. */
		xSleep(50);


		/* Reset port, which implies enabling it. */
		usbd_reset_port(dev, port, &ps);


		/* Get port status again, it might have changed during reset */
		usbd_get_port_status(dev, port, &ps);

		status = ps.wPortStatus;
		change = ps.wPortChange;

#ifdef USB_DEBUG
		sprintf(buf, "uhub_explore: port %d status 0x%04x 0x%04x\n",port, status, change);
		dbg(buf);
#endif //USB_DEBUG


		#define USB_SPEED_LOW  1
		#define USB_SPEED_FULL 2
		#define USB_SPEED_HIGH 3
		#define UPS_LOW_SPEED     0x0200
		#define UPS_HIGH_SPEED    0x0400

		int speed;
		/* Figure out device speed */
		if (status & UPS_HIGH_SPEED)
			speed = USB_SPEED_HIGH;
		else if (status & UPS_LOW_SPEED)
			speed = USB_SPEED_LOW;
		else
			speed = USB_SPEED_FULL; // The gamepad is a full speed!


		/* Get device info and set its address. */
		usbd_new_device(dev, 0, 1, speed, port, &ps);

#ifdef USB_DEBUG
		dbg("****************\n");
#endif //USB_DEBUG

	}// End for loop



	return 1;
}// End of do_hub_work(..)

















int get_control_msg_for_xpad(ohci_t * ohci, 
					__u8 Addr,
					__u8 request,     // 0x06
					__u8 requesttype, // 0x80
					__u16 value,
					__u16 index,
					__u16 size,
					__u8 *data )
{

	// First, lets desribe what type of message this is!
	devrequest cmd;
	

	cmd.requesttype	= requesttype; //0x80;
	cmd.request		= request;     //0x06;
	cmd.value       = value; //(0x29<<8);
	cmd.index		= index;
	cmd.length		= ((__u16) size);


	xMmLockUnlockBufferPages( (__u32)&cmd, 0x8, 0);
	__u32 real_pcmd = xMmGetPhysicalAddress( (__u32)&cmd);


	__u8 Descriptors[256] = {0};
	xMmLockUnlockBufferPages( (__u32)Descriptors, 256, 0 );
	__u32 real_pDescriptors = xMmGetPhysicalAddress( (__u32)Descriptors );


	//__u32 uTD = (__u32)pTD;
	//uTD += (__u32)0x10;
	//uTD &= 0xfffffff0;

	s_Transferdescriptor *TD;
	TD = (s_Transferdescriptor *)(((__u32 *)ED) + 20);
	__u32 TDA = EDA + 80;
	__u32 realTDA = xMmGetPhysicalAddress( (__u32)TDA );



////////////////////////////////////////////////////////////////////////
//   --Transfer Descriptor TD--
//   Offset	Field		Size	Value		Desc
//   0                  4       0..17       reserved
//                              
//      						18          R  - bufferRounding
//								19..20      DP - Direction/PID
//								                 00b SETUP
//												 01b OUT
//												 10b IN
//												 11b reserved
//								21..23      DI - DelayInterrupt
//	                            24..25      T  - DataToggle
//								26..27      EC - ErrorCount
//								28..31      CC - ConditionCode
//  4                   4                   CurrentBufferPoinnter (CBP)
//	8                   4       0..3        Zero
//	                            4..31       Next TD (NextTD)
// 12                   4                   Buffer End (BE)
//                                             
//(Total Size 16 bytes or 4 dwords)
//
////////////////////////////////////////////////////////////////////////

	__u32 v_format  = 0;
	v_format        |= (0xE<<28); // 1110b - CC
	v_format        |= (0x0<<26); // 00b   - EC
	v_format        |= (0x2<<24); // 10b   - T
	// E2
	v_format        |= (0x0<<21); // 000b  - DelayInterrupt
	v_format        |= (0x0<<19); // 00b   - DR (SETUP)
	v_format        |= (0x0<<18); // 0b    - bufferRound (NO)
	v_format        |= (0x0<<16); // 00b   - reserved
	// 00
	v_format        |= 0x50CA;    // reserved
	// 50CA


	TD[0].Format	= 0xE20050CA;					// Get Descriptor
	TD[0].Buffer	= real_pcmd;  
	TD[0].NextTD	= realTDA + 16; 
	TD[0].BufferEnd	= real_pcmd + 7; 		

	TD[1].Format	= 0xE31450CB;					// Receive Start of Descriptor
	TD[1].Buffer	= real_pDescriptors; 
	TD[1].NextTD	= realTDA + 32;
	TD[1].BufferEnd = real_pDescriptors + 7;


	//-------------------------------------------------------------

	TD[2].Format	= 0xE21450CC;					// Receive Rest of Descriptor
	TD[2].Buffer	= real_pDescriptors + 8;
	TD[2].NextTD	= realTDA + 48;
	TD[2].BufferEnd	= 0;

	TD[3].Format	= 0xE30050CD;					// Queue END
	TD[3].Buffer	= 0;
	TD[3].NextTD	= 0;
	TD[3].BufferEnd	= 0;

////////////////////////////////////////////////////////////////////////
//   --EndPoint Descriptor ED--
//   Offset	Field		Size	Value		Desc
//   0                  4       Bitmap           
//	                            0..6        FA - Function Address
//	 							
//		                        7..10       EN - EndpointNumber
//								11..12      D  - Direction
//								                 00b GetDir From TD
//												 01b OUT
//												 10b IN
//												 11b GetDir From TD
//								13          S  - Speed (Full Speed=0)
//								14          K  - sKip
//								15          F  - Format
//								                 0 - Control/Bulk/Int
//												 1 - Isochronous
//	                            16..26      MPS  MaximumPacketSize
//							    27..31      reserved
//	4                   4       Bitmap
//	                            0..3        Zero Aligment
//								4..31       TD Queue Tail Pointer (TailP)
//	8                   4       Bitmap
//	                            0           H  - Halted
//								1           C  - toggleCarry
//								2..3        reserved
//								4..31       TD Queue Head Pointer (HeadP)
//	12                  4       Bitmap
//	                            0..3        Zero Aligment
//								4..31       Next Endpoint Descriptor (NextED)
//
//(Total Size 16 bytes or 4 dwords)
//
////////////////////////////////////////////////////////////////////////

	//0x00081801

	//__u32 format = 0x00401801;
	__u32 format = 0x00401800;
	ED[1].Format = format;

	ED[1].Headptr = realTDA;
	ED[1].Tailptr = realTDA + 32;
	ED[1].Format  &= 0xFFFFFF00;                     // Clear old address
	ED[1].Format  += Addr;                           // Insert new address


	// ED[i].Format = AUTOIO | 0x402000; // AUTOIO 0x1800L

	TD[1].BufferEnd = real_pDescriptors + size - 1;


	ohci->regs->cmdstatus  |= 2;			         // CommandStatus
	ohci->regs->control	   = 0x90;		             // set CLE
	ohci->regs->intrstatus = ohci->regs->intrstatus; // clear all Interruptflags


	// wait for execution
	//dbg("waiting for execution\n");
	do
	{

	}while(  (ohci->regs->intrstatus & 2)== 0 );

	xSleep(10);

	// ERRORS?
	ohci_hcca *hcca = (ohci_hcca*)ohci->hcca;		// HCCA
	hcca->done_head &= 0xfffffffe;					// DoneHead in HCCA

	if( (hcca->done_head>>28) !=0 )
	{

#ifdef USB_DEBUG
		dbg("\nError Occured\n");
#endif //USB_DEBUG

		return 1;
	}

	//------------------------------------------------------------------

	// Where all done and finished now, so we set our ED's to our
	// Queue END where they behave and wait.
	ED[1].Headptr = realTDA + 48;
	ED[1].Tailptr = realTDA + 64;

	if( Descriptors[0] < size) size = Descriptors[0];


#ifdef USB_DEBUG
	// Few debug lines
	#define  OHCI_TD_GET_EC(x)      (((x) >> 26) & 3) 
	#define  OHCI_TD_GET_CC(x)      ((x) >> 28) 

	__u32 ErrorCount     = OHCI_TD_GET_EC( TD[0].Format );
	__u32 ConditionCode  = OHCI_TD_GET_CC( TD[0].Format );

	sprintf(buf, "TD[0]:ErrorCount: %d\n", ErrorCount); dbg(buf);
	sprintf(buf, "TD[0]:ConditionCode: %d\n", ConditionCode); dbg(buf);

	ErrorCount     = OHCI_TD_GET_EC( TD[1].Format );
	ConditionCode  = OHCI_TD_GET_CC( TD[1].Format );

	sprintf(buf, "TD[1]:ErrorCount: %d\n", ErrorCount); dbg(buf);
	sprintf(buf, "TD[1]:ConditionCode: %d\n", ConditionCode); dbg(buf);
#endif //USB_DEBUG

	xSleep(10);

	xmemcpy( data, Descriptors, size);

	ED[1].Format = 0x00081801;

	return 0;
}



int usbd_do_request_big_packet(usbd_device * dev, devrequest *req, void *data)
{
	return  get_control_msg_for_xpad(dev->p_ohci, 
							dev->address,
							req->request,
							req->requesttype,
							req->value,
							req->index,
							req->length, // e.g. size buffer
							(__u8*)data );

}// End of usbd_do_request(..)




