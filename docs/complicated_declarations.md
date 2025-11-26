## Complicated Declarations (C)

`int *f()`\
&emsp;&emsp;f:&emsp;function returning pointer to int\
`int (*pf)()`\
&emsp;&emsp;pf:&emsp;pointer to function returning int\
`char **argv`\
&emsp;&emsp;argv:&emsp;pointer to pointer to char\
`int (*daytab)[13]`\
&emsp;&emsp;daytab:&emsp;pointer to array[13] of int\
`int *daytab[13]`\
&emsp;&emsp;daytab:&emsp;array[13] of pointer to int\
`void *comp()`\
&emsp;&emsp;comp:&emsp;function returning pointer to void\
`void (*comp)()`\
&emsp;&emsp;comp:&emsp;pointer to function returning void\
`char (*(*x())[])()`\
&emsp;&emsp;x:&emsp;function returning pointer to array[] of\
&emsp;&emsp;pointer to function returning char\
`char (*(*x[3])())[5]`\
&emsp;&emsp;x:&emsp;array[3] of pointer to function returning\
&emsp;&emsp;pointer to array[5] of char
