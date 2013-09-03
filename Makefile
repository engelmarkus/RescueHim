all:
	+$(MAKE) -C src

.PHONY: doc
doc:
	+$(MAKE) doc -C doc

.PHONY: clean
clean:
	+$(MAKE) clean -C src
	+$(MAKE) clean -C doc

