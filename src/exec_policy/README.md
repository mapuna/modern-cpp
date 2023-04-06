# Execution Policies of STL `algorithms`

STL `algorithms` is a set of predefined functions on containers like 
arrays, vectors. These functions have a defined execution policy that 
determines how they execute and interact with the hardware.

1. `std::execution::sequenced_policy`: An algorithm should execute sequentially (default)
2. `std::execution::parallel_policy`: An algorithm should execute in parallel (multithreaded model)
3. `std::execution::unsequenced_policy`: An algorithm may be vectorized and executed in a single 
    thread in a SIMD like model
4. `std::execution::parallel_unsequenced_policy`: An algorithm should execute in parallel and may
    may produce non-deterministic results, in a multithreaded + SIMD like model

## `g++` Compilation
Required `g++` (`gcc`) >= 9.0

```
g++ -std=c++20 <source-file> -o <dest binary> -ltbb <other flags for your liking>
```
