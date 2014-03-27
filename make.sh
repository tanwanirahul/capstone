#! /usr/bin/env bash

# Capstone Disassembler Engine
# By Nguyen Anh Quynh <aquynh@gmail.com>, 2013>

MAKE=make
source setting.mk

function build {
	${MAKE} clean

	if [ ${CC}x != x ]; then
		${MAKE} CC=$CC
	else
		${MAKE}
	fi
}

function install {
	if [ ${CC}x != x ]; then
		${MAKE} CC=$CC install
	else
		${MAKE} install
	fi
}

case "$1" in
  "" ) build;;
  "default" ) build;;
  "install" ) install;;
  "uninstall" ) ${MAKE} uninstall;;
  * ) echo "Usage: make.sh [install|uninstall]"; exit 1;;
esac
