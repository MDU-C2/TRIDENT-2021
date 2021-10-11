# TRIDENT-2021
An extention of the original NAIAD project where an autonomous platform is made for assiting with location data to the Naiad.
![Make this a cool image of the NAIAD](https://i0.wp.com/robotnyheter.se/wp-content/uploads/2013/12/Naiad_AUV_robot_open.jpg?resize=900%2C429&ssl=1)


__Git guidelines:__ We're utilizing git flow in this project, this means that we have a few layers of branches for safety of the release version.

The workflow will look like illustrated in this picture.
![Git flow](https://wac-cdn.atlassian.com/dam/jcr:34c86360-8dea-4be4-92f7-6597d4d5bfae/02%20Feature%20branches.svg?cdnVersion=1841)
Each feature has a separate branch e.g. one for ROS, This is the branch you push to each day. This is like your isolated experiment box.
When a feature is done or after a certain time period, you push your progress to the development branch called "dev".   
__You do NOT push to main ever.__  
Main is for each stable release of the project, so there will always be a working version. This branch is updated at regular intervals when the upcoming release is due.

If you're comfortable with CLI then there exists a wrapper called git flow.  
More info here: https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow  
Otherwise I suggest using Git Kraken for a visual representation.  
You can sign up with your student mail: https://www.gitkraken.com/student-resources

## Git CLI cheat sheet
[Cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)

Add files to the repository  
```
git add file_name
```
Commit files to repository with a message: 
```
git commit -sm "Message"
```
Pull BEFORE pushing anything 
```
git pull
```
Upload files to repository: 
```
git push
```
Did you fuck up? Don't push until you've sorted it out.
```
git reset
```
or
```
git rm file_name
 ```
## Installing git flow:

#### Windows 
git flow is included in git bash terminal: https://git-scm.com/downloads

#### Ubuntu
```
sudo apt update  
sudo apt install git-flow
```
## Initializing git flow
Create a local branch named "dev"  
```
git branch dev
```
Run git flow init command
```
git flow init
```
Set main as the "release branch" when promted  
Set dev as "next release branch" when prometed  
Press enter for all of the other options.

## Did you fuck up?

reinitialize with this command  
```
git flow init -f
```
## Using git flow

To begin on your new feature:  
```
git flow feature start feature_name
```
To push your finished feature to dev:  
```
git flow feature finish feature_name
```
All done! :)  
__Between starting and finish of a feature you use the git tool you want as you usually do. CLI or GUI.__

