--huge Let's Shell

--newpage topic
--author Jiaping Zhu
--title Basic Knowledge of Shell
--date today

--newpage shell programming
--heading First Shell
--beginshelloutput
$ ls
examples  p.sh  shell.tpp  tpp
--endshelloutput
--beginshelloutput
$ ls |wc -l
4
--endshelloutput
---
--center write the command to file
--beginshelloutput
$ cat >countfile.sh 
ls|wc
^D
--endshelloutput
--newpage shell programming 2
--heading Running Shell
---
--beginshelloutput
$ chmod +x countfile.sh 
$ ./countfile.sh 
4
--endshelloutput
---
--center Write a file differently
--beginshelloutput
$ cat >countfile.sh <<EOF
> ls | wc
> EOF
--endshelloutput

--newpage introduce of "#!"
--heading The "#!" in first line
The portable countfile.sh looks like 
--beginoutput
#!/bin/sh
ls|wc -l
--endoutput
- "#!" is in first line
- it tell which application used as interpreter
- Other script language also use "#!"
---
--center "#!" used in sed script
--beginoutput
#!/usr/bin/sed -f
10q
--endoutput


--newpage shell and process
--heading Shell and Process
Let's look at a shell file cd.sh
--beginoutput
#!/bin/sh
cd tmp/
echo "hello,world" >hello.txt
--endoutput
--center "Question:What's result of following commands ?"
--beginshelloutput
$ ./cd.sh 
$ cat hello.txt
--endshelloutput

--newpage shell and process(Cont.)
--heading Shell and Process(Cont.)
--beginshelloutput
$ ./cd.sh 
$ cat hello.txt
cat: hello.txt: No such file or directory
--endshelloutput
---
--center Don't spawn a process to run the shell
--beginshelloutput
$ source cd.sh 
$ cat hello.txt
hello,world
--endshelloutput
- "source cd.sh" == ". cd.sh" (abbrevation)

--newpage shell command syntax
--heading shell command syntax
--beginoutput
ENV=ENV_VAR COMMAND OPTION1 OPTION2 ... 
--endoutput
--center short shell options
--beginoutput
$ ls -l -t whizprog.c
$ ls -lt whizprog.c  #same command as above
--endoutput
--center '--' end shell options
--beginoutput
$ touch -- -h  # "-h" will be taken as a filename
--endoutput

--newpage shell command syntax(cont.)
--heading shell command syntax(cont.)
--center mutil-command in a line
--beginoutput
$ shell_1; shell_2; shell_3 ...
--endoutput
--center run the shell in background with '&'
--beginoutput
$ shell_command &
--endoutput

--newpage shell command types
--heading Different types of Shell command
--beginslideleft
1. Shell Builtin
--endslideleft
--beginshelloutput
$ type cd
cd is a shell builtin
--endshelloutput

---
--beginslideleft
2. Shell Alias
--endslideleft
--beginshelloutput
type ls
ls is aliased to `ls --color=auto'
--endshelloutput

---
--beginslideleft
4. External Command (other process)
--endslideleft
--beginshelloutput
$ type ifconfig 
ifconfig is /sbin/ifconfig
--endshelloutput


--newpage Shell Function
--heading Shell Type (Cont.)
--beginslideleft
3. Shell function
--endslideleft
--beginshelloutput
$ cat >funs.sh <<EOF
function findname() { find . -name \$1

}
EOF
$ source funs.sh 
$ type findname 
findname is a function
findname () 
{ 
    find . -name $1
}
--endshelloutput

--newpage Shell Variable
--heading Shell Variable
Syntax:
--beginoutput
$ DISPLAY=:0
--endoutput
"export" make the variable to sub-process
--beginshelloutput
$ DISPLAY=:0; export DISPLAY
$ export DISPLAY=:0 #the command is same to the above
--endshelloutput
get a var value with "$" prefix
--beginshelloutput
$ tmpDISPLAY=$DISPLAY
--endshelloutput

--newpage Shell Variable(Cont.)
--heading Shell Variable(Cont.)
'echo' and 'printf' display a variable
--beginshelloutput
$ echo $GTK_IM_MODULE
ibus
--endshelloutput
Very import variable PATH
--beginshelloutput
$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
--endshelloutput
'env' list all the shell variable
--beginshelloutput
$ env
--endshelloutput

--newpage I/O Redirection
--heading I/O Redirection
default standard input (fd:0)
default standard output (fd:1)
default standard error  (fd:2)
--center Change the default input with "<"
--beginshelloutput
$ patch -p1 <patchfile
--endshelloutput
--center Change the default input with ">" or ">>"
--beginshelloutput
$ find . -name "*.cpp" >find.result
$ find . -name "*.[ch]" >>find.result #>> append output to the file
--endshelloutput
You can take "<" or ">" as funnels, which indicate data direction

--newpage I/O Redirection(Cont.)
--heading I/O Redirection(Cont.)
--center Change the default error with ">" or ">>"
--beginshelloutput
$ find /usr/share/ -name "*.py" 2>find.result
$ find . -name "*.sh" 2>&1 >find.result # &1 means default output
--endshelloutput
--center Pipeline "|" used in shell
data transfer from one process to another process
--beginshelloutput
$ cat namelist.txt | sort | uniq
--endshelloutput

--newpage I/O Redirection Special File
--heading I/O Redirection Special File
--center file /dev/null
the data written to /dev/null are abandoned
--beginoutput
if grep QApplication main.cpp  >/dev/null
then
...
else
...
fi
--endoutput
--center file /dev/tty connect to your working terminal
--beginoutput
stty -echo
read password </dev/tty
stty echo
--endoutput

--newpage end
--sethugefont block 
--huge Thank You !
--sethugefont standard 
