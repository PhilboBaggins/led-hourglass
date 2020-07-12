DIA_FILES := $(wildcard *.dia)
PNG_FILES := $(patsubst %.dia,%.png,$(DIA_FILES))

.PHONY: all clean

all: $(PNG_FILES)

%.png: %.dia
	dia --nosplash --export=$@ $<

clean:
	rm -f $(ALL)
