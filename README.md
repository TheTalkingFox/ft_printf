# ft_printf – Because printf wasn’t enough

This is my custom implementation of the famous **`printf`** function in C.  
It supports multiple format specifiers, handles variable arguments, and prints with style.  

---

## ✨ Supported Conversions
`ft_printf` handles all the classics:

- `%c` – Print a single character  
- `%s` – Print a string  
- `%p` – Print a memory address (pointer)  
- `%d` / `%i` – Print integers (signed)  
- `%u` – Print unsigned integers  
- `%x` / `%X` – Print numbers in lowercase/uppercase hex  
- `%%` – Print a literal `%`  

---

## ✨ Features
- **Variadic arguments** via `<stdarg.h>`
- **Buffer-free printing** (direct write to stdout)  
- **Error handling** with correct return values  
- Works as a **drop-in replacement** for standard `printf` (well… mostly)  

---

## ✨ Technical Challenges
While building this project, I learned:  
- How to **parse format strings** and handle edge cases  
- Converting numbers to **different bases**  
- Handling **pointers & memory addresses**  
- Managing **variadic functions** with `va_list`, `va_start`, `va_arg`, and `va_end`  

---
