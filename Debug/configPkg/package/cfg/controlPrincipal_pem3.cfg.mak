# invoke SourceDir generated makefile for controlPrincipal.pem3
controlPrincipal.pem3: .libraries,controlPrincipal.pem3
.libraries,controlPrincipal.pem3: package/cfg/controlPrincipal_pem3.xdl
	$(MAKE) -f C:\Users\Ledx\DOCUME~1\TIPROJ~1\colmenav1/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Ledx\DOCUME~1\TIPROJ~1\colmenav1/src/makefile.libs clean

