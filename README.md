<div align=center>

# Pipex

### 42 Common Core / circle #2
<i>This project aims to deepen the understanding of two concepts : Redirections and Pipes.
<br>
It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.</i>

##

### Final grade
[![abrisse's 42 pipex Score](https://badge.nimon.fr/api/v2/clw51aj8x026501rzp5ef4x2f/project/2620562)](https://github.com/Nimon77/badge42)

### Subject
English version [here](https://github.com/abrisse16/42-subjects/blob/7385a594afd19b06ab40ed62b5e8c818d2d8bd21/pipex-subject-v2.en.pdf)
<br>
French version [here](https://github.com/abrisse16/42-subjects/blob/7385a594afd19b06ab40ed62b5e8c818d2d8bd21/pipex-subject-v2.fr.pdf)

</div>

---

## The project

In this project, we must create a program that will reproduce the behavior of the following shell command :

```sh
< file1 cmd1 | cmd2 > file2
```

The <i>pipe</i> command can redirect the output of a command to the input of another command.

## Usage

Clone this repository :

```sh
git clone https://github.com/abrisse16/42-pipex.git path/to/repository
```

In your local repository, run `make`

To run `pipex`, use the following command :

```sh
./pipex file1 cmd1 cmd2 file2
```

> - <i>file1</i> and <i>file2</i> are the input and output files respectively.
> - <i>cmd1</i> and <i>cmd2</i> are shell commands with their parameters.

---
<div align=center>
	<a href="mailto:abrisse@student.42.fr">abrisse@student.42.fr</a>
</div>