rm -f ./.build/cocot46_default.*
echo "###### make ######################################"
make cocot46:default:uf2

if [ ! -e ./.build/cocot46_default.uf2 ]; then
  exit
fi

echo "###### umount ####################################"
sudo umount /Volumes/cocot46

echo "###### dfu #######################################"
expect -c "
  spawn screen /dev/tty.usbmodem0000000000015
  send \"dfu\\n\"
  expect
  exit 0
"

echo "###### sleep #####################################"
sleep 3

echo "###### cp ########################################"
cp -p ./.build/cocot46_default.uf2  /Volumes/BLEMICROPRO/
