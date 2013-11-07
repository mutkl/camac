#!/bin/bash
echo 'chowing SCSI access in /dev'
sudo chown $USER /dev/sg0
sudo chown $USER /dev/sg1