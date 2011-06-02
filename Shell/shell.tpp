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

--newpage end
--sethugefont block 
--huge Thank You !
--sethugefont standard 
