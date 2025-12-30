# Replace "hello" with your module name (without .c extension)
# obj-m: "Object files to build as Modules"
# +=: Add to the list (in case you have multiple modules)
obj-m += user_input.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean