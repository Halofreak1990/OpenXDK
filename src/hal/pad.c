#include <stdlib.h>
#include <memory.h>
#include <usb/ohci.h>
#include <usb/hub.h>
#include <usb/bulk.h>
#include <hal/pad.h>
#include <hal/xbox.h>
#include <openxdk/debug.h>

extern __u8 found; // declared at the top of ohci.cpp

int XInitInput(XUSBControl *xcontrol)
{
	__u8 Buffer[256];


	ohci_t * my_ohci = &(xcontrol->my_ohci);

#ifdef USB_DEBUG
	debugPrint("xInitInput\n");
#endif //USB_DEBUG

	int Ports = FindOHC( my_ohci, (void*)0xfed00000 );


#ifdef USB_DEBUG
	if( Ports==0 ) debugPrint("Error no ports found\n");
#endif //USB_DEBUG

	//for( int i=0; i<Ports; i++)
	int i=0;
//	{

		int DEV = FindDev(my_ohci, i);

#ifdef USB_DEBUG
		switch (DEV) 
		{
			case 0: { sprintf(buf,"\n*NO* device found at Port %d\n", i); 		debugPrint(buf); }	break;
			case 1: { sprintf(buf,"\nlowspeed-device found at Port %d\n", i);	debugPrint(buf); }	break;
			case 2: { sprintf(buf,"\nfullspeed-device found at Port %d\n", i);	debugPrint(buf); }
        };
#endif //USB_DEBUG
		//if( DEV == 0 ) return;

		s_USB_Devicedescriptor DD[4] = {0};

		ResetPort(my_ohci, i);
		SetAddres(my_ohci, 0, found);

#ifdef USB_DEBUG
		debugPrint("\n\ngood to go\n\n");
#endif //USB_DEBUG

		GetDesc(my_ohci, found, 1, 0, 18, Buffer);

		memcpy(&(DD[0]), Buffer, 18);

#ifdef USB_DEBUG
		DebugDescriptor( &DD[0] );
		sprintf(buf, "ConfigNumber:%x\n", DD[0].ConfigNumber ); debugPrint(buf);
#endif //USB_DEBUG

		s_USB_Configurationdescriptor CD[4][8]={0};
		s_USB_Interfacedescriptor ID[4][8][8] = {0};
// commented out by CE so that we don't get a GCC generated call to alloca
//		s_USB_Endpointdescriptor ED[4][8][8][8]={0};
	
		for (int j = 1; j <= DD[i].ConfigNumber; j++)
        {
			int index = 0;

			SetConfigur(my_ohci, found, j);
			GetDesc(my_ohci, found, 2, 0, 9, Buffer); // Configdescr.
			memcpy(&CD[i][j - 1], Buffer, 9);

#ifdef USB_DEBUG
			DebugConfigDescriptor( &(CD[i][j-1]) );
#endif //USB_DEBUG

			GetDesc(my_ohci, found, 2, 0, (__u8) *((__u16 *) &Buffer[2]), Buffer); // Configdescr.
			memcpy(&CD[i][j - 1], Buffer, 9);

#ifdef USB_DEBUG
			DebugConfigDescriptor( &(CD[i][j-1]) );
#endif //USB_DEBUG

			
			index += 9;
			for (int k = 0; k < CD[i][j - 1].NumberofInterfaces; k++)
			{

				
				memcpy(&ID[i][j][k], Buffer + index, 9);
#ifdef USB_DEBUG
				DebugInterfaceDescriptor( &(ID[i][j][k]) );
#endif //USB_DEBUG


				if (ID[i][j][k].InterfaceIndex)
				{
				  GetDesc(my_ohci,found, 3, ID[i][j][k].InterfaceIndex, 8, Buffer); // String
				  //DebugInterfaceDescriptor( &ID[i][j][k] );
				  GetDesc(my_ohci,found, 3, ID[i][j][k].InterfaceIndex, Buffer[0], Buffer); // String
				  
				  for (j = 1; j < (Buffer[0] / 2); j++)
					Buffer[j + 1] = Buffer[2 * j];
				  Buffer[j + 1] = 0;

				  s_USB_Stringdescriptor *SD = (s_USB_Stringdescriptor *) malloc(16384);
				  memcpy((__u8 *) SD, Buffer, Buffer[0]);
#ifdef USB_DEBUG
				  sprintf(buf, "\nInterface %d: %s\n", k + 1, &Buffer[2]); debugPrint(buf);
#endif //USB_DEBUG

				};// End if(..)

				index += 9;
				for (int l = 0; l < ID[i][j][k].NumberofEndpoints; l++)
				{
				
				  // Causes a link error?
				  //memcpy(&ED[i][j][k][l], Buffer + index, 9);
				
#ifdef USB_DEBUG
				  //DebugEndPointDescriptor( &ED[i][j][k][l] );
#endif //USB_DEBUG
				};

			}// End for loop k


			// we set the default configuration here 
	        //usb_set_configuration(dev, dev->config[0].bConfigurationValue))
//	usb_set_configuration(my_ohci, found, CD[i][j-1].ConfigValue);
			//CD[i][j-1].ConfigValue;

			set_control_msg(my_ohci, found,
	              USB_REQ_SET_CONFIGURATION, 0, CD[i][j-1].ConfigValue, 0, 0, NULL);


		}// End for loop j
		

	//}




		//-----------------------work on the hub!-------------------------/

		// ref: http://fxr.watson.org/fxr/source/dev/usb/uhub.c
		///
		// To have the best chance of success we do things in the exact same
		// order as Windoze98.  This should not be necessary, but some
		// devices do not follow the USB specs to the letter.
		//
		// These are the events on the bus when a hub is attached:
		//  Get device and config descriptors (see attach code)
		//  Get hub descriptor (see above)
		//  For all ports
		//     turn on power
		//     wait for power to become stable
		// (all below happens in explore code)
		//  For all ports
		//     clear C_PORT_CONNECTION
		//  For all ports
		//     get port status
		//     if device connected
		//        wait 100 ms
		//        turn on reset
		//        wait
		//        clear C_PORT_RESET
		//        get port status
		//        proceed with device attachment
		///


#ifdef USB_DEBUG
		debugPrint("\n\nHUB INTERIGATION AND SETTING UP\n\n");
#endif //USB_DEBUG

		
		memset(Buffer, 0, 255);

		//usb_get_device_descriptor(my_ohci, 1, 18, Buffer);
		//DebugDescriptor( (s_USB_Devicedescriptor *)Buffer );

		usbd_device dev;
		dev.p_ohci  = my_ohci;
		dev.address = found; // root hub should be addr 1


		do_hub_work(&dev);




		// Testing...gamepad 1 is allocated to addr 3

		
		//Assumptions - for this small test section...I've assumed taht only 
		//a single gamepad is plugged in.
		

#ifdef USB_DEBUG
		debugPrint("\n\n--gamepad_0---\n\n");
#endif //USB_DEBUG



		//Getting Descriptor
		s_USB_Devicedescriptor devdesc = {0};
		dev.address = 3;		

		devrequest req = {0};
		req.requesttype = UT_READ_DEVICE;
		req.request     = UR_GET_DESCRIPTOR;
		req.value = 0;
		req.value |= (0x00ff & 0);
		req.value |= (0xff00 & (UDESC_DEVICE<<8));
		req.index       = 0;
		req.length      = 18;

		// What is this new function?...why didn't we use the normal
		// usd_do_request(..)?....hmm...well it seems that the gamepad
		// max packet size is 0x40...and if we use the 0x8 which I've done upto
		// now we only get the first 8 bytes of the desciptor...using this slightly
		// modified version, we get the full descriptor of our gamepad :)
		usbd_do_request_big_packet(&dev, &req, &devdesc);

#ifdef USB_DEBUG
		DebugDescriptor( &devdesc );
#endif //USB_DEBUG


		XSleep(10);
		//-------

		// USB_REQ_SET_CONFIGURATION, 0, configuration, 0, 0, NULL);

		// Set the config descriptor for gamepad

		__u16 bConfigurationValue = 0x01;

		usbd_device dev_temp;
		dev_temp.address  = 3;
		dev_temp.p_ohci   = dev.p_ohci;

		devrequest dr = {0};

		int index = 0;

		dr.requesttype	= UT_WRITE_DEVICE;      // 0x80
		dr.request		= UR_SET_CONFIG;        // 0x09
		dr.value		= bConfigurationValue;  // 0x01
		dr.index		= 0;
		dr.length		= 0;

		usbd_do_request_big_packet(&dev_temp, &dr, 0 );


	return 0;
};// End of xInitInput(..)


int XGetPadCount(XUSBControl *xcontrol)
{
	// currently hard coded to 1.  Need to fix this!!
	return 1;
}

devrequest dr = {0};

int XGetPadInput(XPadState *pad, XUSBControl *xcontrol, int padNumber)
{
	usbd_device dev;
	dev.p_ohci  = &(xcontrol->my_ohci);
	dev.address = 3;  // This will choose the first gamepad it finds, only for debug

	XPadState data_in = {0};



	// bug
	__u16 bConfigurationValue = 0x01;

	//devrequest dr = {0};

	dr.requesttype	= UT_WRITE_DEVICE;      // 0x80
	dr.request		= UR_SET_CONFIG;        // 0x09
	dr.value		= bConfigurationValue;  // 0x01
	dr.index		= 0;
	dr.length		= 0;

	

	// bug
	//while(true)
	{
		//usbd_do_request_big_packet(&dev, &dr, 0 );

		usb_bulk_msg_in(&dev, 20, &data_in);
		memcpy(pad, &data_in, 20);


		//DataDisplay( (void*) &data_in );



		//XSleep(100);

		usbd_do_request_big_packet(&dev, &dr, 0 );
	

		// Some error checking to be put here!
		//if( data_in.structsize == 0 )
		//	break;

	}

	return 0; // no error checking as of yet
}


int XSetPadInput(XPadState *pad, XUSBControl *xcontrol, int padNumber)
{

	usbd_device dev;
	dev.p_ohci  = &(xcontrol->my_ohci);
	dev.address = 3;  // This will choose the first gamepad it finds, only for debug

	// Rumbble...lets see if we can make our gamepad rumble :)

	__u8 data1[6] = {0,6,0,120,0,120};    // rumble data
	usb_bulk_msg(&dev, 6, (void*)data1);  // simple bulk send function (in pad.c/.h)
			
	__u8 data2[6] = {0,6,0,0,  0,0  };
	usb_bulk_msg(&dev, 6, (void*)data2);

	return 0; // no error checking as of yet
}


int XReleaseInput(XUSBControl *xcontrol)
{
	return 0; // no error checking as of yet
}



