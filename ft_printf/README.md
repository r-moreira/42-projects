## 🚀 The the third project at 42 college!
The ft_printf function writes the C string pointed by format to the standard output (stdout). If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.\
In this project we are introduced to new concepts like variadic function.\
We need to make libftprintf.a lib that contains this function

---

## 📖 Subject
There is a PDF in the subject folder containing details about the project.

---

## ✅ Supported features

| Specifier | Description |
| ------------ | ------------ |
|**c**| character|
|**s**|	NULL - terminated string|
|**p**|	pointer memory address|
|**d**| signed decimal base|
|**i**|	signed decimal base|
|**u**|	unsigned decimal base|
|**x**|	unsigned hex base (lowercase)|
|**X**|	unsigned hex base (uppercase)|
|**%**|	'%' char literal|

| Flag | Description |
| ------------ | ------------|
|**-**|	left-justify within he given field width; right justification is the default|
|**0**|	left-pads the number with zeroes (0) instead of spaces when padding is specified|

| Width| Description |
| ------------ | ------------ |
|**(number)**|Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|*|The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

| Precision | Description |
| ------------ | ------------ |
|**.number**|For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. For s: this is the maximum number of characters to be printed. If the period is specified without an explicit value for precision, 0 is assumed.|
|*|The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

---

## 🖥️ Compiling the lib
Note: The project was developed on MacOS, in other operating systems there may be undefined behaviors.

```bash

# Clone the repository
git clone https://github.com/r-moreira/42-projects.git

# Enter the project directory
cd libft/

# to compile libftprintf.a run
make

# include "libftprintf.h" in your project
Now you can compile the libftprintf.a with your files :)
```
