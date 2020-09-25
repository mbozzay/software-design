## 
#  setting the module name
#  ...
MODULE	 = quaternion

## 
#  setting the module output file.  (p2_hash_table.o)
#  ...
obj-m += $(MODULE).o

## 
#  finding the kernel build directory
#  ...

## 
#  fetching the current directory
#  ...
PWD := $(shell pwd)

## 
#  creating the make all function for the current module
#  ...
all: $(MODULE)


## 
#  for all executable and c files, output the name and use our compiler (gcc) to compile
#  ...
%.o: %.c
	@echo "  CC      $<"
	@$(CC) -c $< -o $@

## 
#  add all modules from the current directory to the kernel directory
#  ...

## 
#  delete all modules from the kernel directory on make clean
#  ...
clean:
	$(MAKE) -C M=$(PWD) clean
