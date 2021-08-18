all: cmp_overhead_shared_ptr cmp_overhead_plain_ptr 

cmp_overhead_plain_ptr: shared_ptr_overhead.cpp shared_ptr_inst
	g++ -pthread -O3 shared_ptr_overhead.cpp -o cmp_overhead_plain_ptr

cmp_overhead_shared_ptr: shared_ptr_overhead.cpp
	g++ -DSHARED -pthread -O3 shared_ptr_overhead.cpp -o cmp_overhead_shared_ptr
shared_ptr_inst: shared_ptr_lost_ptr.cpp
	g++ -g -fsanitize=address shared_ptr_lost_ptr.cpp -o shared_ptr_inst


