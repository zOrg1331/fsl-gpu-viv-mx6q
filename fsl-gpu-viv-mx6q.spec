Name: fsl-gpu-viv-mx6q
Version: 12.09.01
Release: alt1
Summary: GPU driver and apps for imx6
License: Proprietary
Group: System/Libraries
Url: http://www.freescale.com/lgfiles/NMG/MAD/YOCTO/
Packager: Pavel Nakonechny <pavel.nakonechnyk@skitlab.ru>

AutoReq: no
AutoProv: no
AutoReqProv: no

Source: %name-%version.tar
Patch: %name-%version-%release.patch

Conflicts: libgal
Provides: libGAL.so

%description
%summary

%package -n fsl-gpu-viv-mx6q-devel
Summary: Header files for GPU driver for imx6
Group: Development/C

Requires: fsl-gpu-viv-mx6q = %version

%description -n fsl-gpu-viv-mx6q-devel
%summary

%prep
%setup -q
%patch -p1

%build

%install
mkdir -p %buildroot/usr
cp -a usr/* %buildroot/usr

%files
/usr/lib/*.so*
/usr/lib/direct*

%files -n fsl-gpu-viv-mx6q-devel
/usr/include/*

%set_verify_elf_method no

%changelog
* Sun Mar 24 2013 Pavel Nakonechny <pavel.nakonechny@skitlab.ru> 12.09.01-alt1
- initial build
