prefix		:= /usr/local
abs_top_srcdir	:= /scratch/seah/chipyard-supernova/generators/supernova/software/build/..
XLEN            := 64
RISCVTOOLS      := @RISCVTOOLS@
ROCC = examples
RUNNER         := "spike --extension=dma "

.PHONY: all slam clean 
all: slam 

vars = \
	abs_top_srcdir=$(abs_top_srcdir) \
	XLEN=$(XLEN) \
	PREFIX=$(ROCC)-$@ \
	src_dir=$(abs_top_srcdir)/$@ \
	RISCVTOOLS=$(RISCVTOOLS)

slam:
	mkdir -p $@
	$(MAKE) -C $@ -f $(abs_top_srcdir)/$@/Makefile $(vars)

clean:
	$(MAKE) -C slam -f $(abs_top_srcdir)/slam/Makefile abs_top_srcdir=$(abs_top_srcdir) PREFIX=$(ROCC)-slam clean

test-baremetal-slam:
	make -C slam	\
	        -f $(abs_top_srcdir)/slam/Makefile \
                TARGET_MAKEFILE=$(abs_top_srcdir)/slam/Makefile \
		abs_top_srcdir=$(abs_top_srcdir) \
	 	src_dir=$(abs_top_srcdir)/slam \
	 	XLEN=$(XLEN) \
	 	PREFIX=$(ROCC)-slam \
		RISCVTOOLS=$(RISCVTOOLS) \
		RUNNER=$(RUNNER) \
		run-baremetal

test-baremetal: test-baremetal-slam
	make -C slam	\
	        -f $(abs_top_srcdir)/slam/Makefile \
                TARGET_MAKEFILE=$(abs_top_srcdir)/slam/Makefile \
		abs_top_srcdir=$(abs_top_srcdir) \
	 	src_dir=$(abs_top_srcdir)/slam \
	 	XLEN=$(XLEN) \
	 	PREFIX=$(ROCC)-slam \
		RISCVTOOLS=$(RISCVTOOLS) \
		RUNNER=$(RUNNER) \
	        run-baremetal
