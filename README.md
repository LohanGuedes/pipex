<h1 align="center">Welcome to pipex 👋</h1>
<p>🧪 Project to understand more about pipes, processes and file manipulation </p>

---

- Status: Finished
- Result: 104%

---

## Install

```sh
git clone https://github.com/peguimasid/42-Pipex.git pipex
cd pipex
make
```

## Usage

1. Create a `infile.txt` file inside project `pipex` folder

```
I'm going to catch this line because contain a "42" string
this line also contain a "42" string
I'm not going to catch this line
I'm going to be catch too, 42 is awesome
forty two 42
What am i doing here?
```

2. Run the program passing the infile and outfile of the commands.

```sh
 make && infile.txt "cat" "grep 42" outfile.txt
 cat outfile.txt
```


3. Run `cat outfile.txt` and you going to see the output of the commands:

```
I'm going to catch this line because contain a "42" string
this line also contain a "42" string
I'm going to be catch too, 42 is awesome
forty two 42
```

## Author

👤 **Lohan Guedes**

- Github: [@lguedes](https://github.com/lohanguedes)
- LinkedIn: [@lohan-guedes](https://www.linkedin.com/in/lohan-guedes-0349b5239/)

## Show your support

Feel free to fork this project and send a pull request to it! I would love to see possible improvements :mending_heart:.
Give a ⭐️ if this project helped you!
