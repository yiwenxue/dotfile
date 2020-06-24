#!/bin/bash

config="${HOME}/.emacs"
configdir="${HOME}/.emacs.d"

echo "Installing yiwen's emacs configurations"

if [ -d ${configdir} ]
then 
	echo "Backup initial profile"
	if [ -f ${config} ]
	then
		mv ${config} ${config}.bak
	fi
	mv ${configdir} ${configdir}.bak
fi

echo "Installing..."
mkdir -p ${configdir}
cp ./* ${configdir}/ -rf 
cp ./emacs_cli.desktop ${HOME}/.local/share/applications 

echo "Done"
echo "Enjoy it!"
