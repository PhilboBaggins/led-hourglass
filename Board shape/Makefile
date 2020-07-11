
ALL := hourglass.scad hourglass.dxf

.phony: all clean

all: $(ALL)

hourglass.scad: hourglass.svg
	echo "import(\"$<\");" > $@

hourglass.dxf: hourglass.scad hourglass.svg
	openscad $< -o $@

clean:
	rm -f $(ALL)
