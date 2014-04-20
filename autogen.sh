echo "Generating configuration files for $package, please wait..."

echo "  aclocal"
aclocal
echo "  autoconf"
autoconf
echo "  automake --add-missing"
automake --add-missing

