for_each_free_mem_range [中文教程](https://biscuitos.github.io/blog/MMU-ARM32-MEMBLOCK-for_each_free_mem_range/)
--------------------------------------------

* function: Traverse all free memory regions.


## Usage

* patch file

```
git am *.patch kernel_src/
```

* driver file

```
Device Driver--->
    [*]BiscuitOS Driver--->
        [*]Memblock allocator
            [*]for_each_free_mem_range()
```