add wave *

force clock 1 20 ns, 0 40 ns -repeat 40
force reset 1 0

force number_a 1100000000001100000000000000000000000000000000000000000000000000

force number_b 1100000000001100000000000000000000000000000000000000000000000000


force isready 1 1 

run 4820

quit
