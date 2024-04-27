SMT=./cvc5-Linux
PROJ_FILE=projekt2.smt2
REFERENCE_OUTPUT=out_ref
all:
# search if cvc5 is installed
	@which $(SMT) > /dev/null || (echo "cvc5 is not installed. Install it using 'make install'"; exit 1)
# run
	@$(SMT) $(PROJ_FILE) > out
# compare output
	@diff out $(REFERENCE_OUTPUT)

install:
	@echo "Installing cvc5"
	wget https://github.com/cvc5/cvc5/releases/download/cvc5-1.0.5/cvc5-Linux
	chmod +x cvc5-Linux
