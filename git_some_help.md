# Git_Some_Help by *dan*

### 0.9 test if you have git already installed
    * go in ur commandline or terminal and type git --version
    * if it shows you the version skip to ### 3.
    * if not? ▼

### 1. Set up git:
    * First, you need a terminal(or if you are on Win, use Win Command Line)
    * Then you will need to go to the official git download site: 
    * install it 
    
[the official git download site](https://git-scm.com/downloads)

    * if you would like to install a terminal on your Win, follow this guide:

[easy bash on your Win10](https://www.windowscentral.com/how-install-bash-shell-command-line-windows-10)

### 2. (ONLY FOR WIN USERS)
    * so you get an option during installation that askes you to adjust your path environment,
      you can select Git bash to use a Git-Optimized bash terminal, so i strongly recommend it.
      why? because window's console Command Line sux
    * if you just want to use cmd, select win default console

### 3. git init - uninhibit the ribbit 
    * for win cmd > first go to a folder you would like to hold this project, click on the address bar, then 
      you will see the addr being highlighted, and while its highlighted, type cmd and hit    
      enter, a cmd console window will pop up. Now type git init
    * for mac/linux/unix terminal > open terminal, cd /to/where/ever/your/project/directory/is,
      then type git init
 
### 4. fork my repo and clone it into ur project folder
    * go to my repo(posted in group discussion), then click on fork if you havent already
    * then under your profile, click on the green clone or download button, and click on copy to clipboard
      (or use this link here: https://github.com/CallMeHiroyaGojo/Group_4_SmartPointers.git)
    * type git clone https://github.com/CallMeHiroyaGojo/Group_4_SmartPointers.git
    
### 5. make your own branch and checkout to it
    * type git branch PutYourBranchNameHere (can be whatever, it could yell at you for using illegal 
      characters idk, i named mine dansBranch)
    * type git checkout PutYourBranchNameHere (same branch you created)
    
### 6. now i'll attempt to squish a few essential commands here in a rush cuz i wanna sleep
    * git status, your bread and butter for knowing wth is going on with this shit
    * in order: 1.you want to add whatever, 2.save what you've added(maybe leave a comment), 3.push it 
      onto GitHub (publish)(under your branch ofc, I gets to merge two branches together)
    * 1. type git add yourfilename.something (whatever your file might be, at your project directory ofc)
      (git add file need to be typed every time you modify a file)
        1.5 oh yeah, almost forgot, to add something 
           1.5.1 win cmd type type nul > hello.txt (after you enter, there will be an empty hello.txt,
                 and you can create anything with any extention you pc support)
           1.5.2 mac terminal type touch hello.txt (same as above)
           1.5.3 for both versions, you can type mkdir folder to make a folder(or dir)
    * 2. type git commit -m "I added this and that -dan" in order to save your changes you made locally,
         you need to commit (with a message)
    * 3. type git push -u origin PutYourBranchNameHere
            push means you are uploading your changes to github 
            -u means upstream(tracking) 
            origin means github
            and last field is your branch
    * 4. our each individual work flow should be something like: add > commit > push onto ur branch,
         i'll do something like merge our branches onto the master branch when its ready
    
    

sorry for taking a dump on your english linguistic ocd *laughs in english third language* 

gnite -dan Oct 3 12:56:51am signing off
