# TRIDENT-2021
An extention of the original NAIAD project where an autonomous platform is made for assiting with location detection to the Naiad.
![Make this a cool image of the NAIAD](https://i0.wp.com/robotnyheter.se/wp-content/uploads/2013/12/Naiad_AUV_robot_open.jpg?resize=900%2C429&ssl=1)


__Git guidelines:__ We're utilizing git flow in this project, this means that we have a few layers of branches for safety of the release version.
Each feature has a separate branch E.G one for ROS, This is the branch you push to each day. This is like your isolated experiment box.
When a feature is done or after a certain time period, you push your progress to the development branch called "dev".   
__You do NOT push to main ever.__  
Main is for each stable release of the project, so there will always be a working version.

If you're comfortable with CLI then there exists a wrapper called git flow.  
More info here: https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow  
Otherwise I suggest using Git Kraken for a visual representation.  
You can sign up with your student mail: https://www.gitkraken.com/student-resources

## Git CLI cheat sheet
[Cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)

Add files to repository: 
* __git add [file]__ 

Commit files to repository with a message: 
* __git commit -sm "Message"__

Pull BEFORE pushing anything 
* __git pull__

Upload files to repository: 
* __git push__

Did you fuck up? Don't push until you've sorted it out.
* __git reset__ or __git rm file_name__

## Installing git flow:

#### Windows 
git flow is included in git bash terminal: https://git-scm.com/downloads

#### Ubuntu
* __sudo apt update__  
* __sudo apt install git-flow__

## Initializing git flow
Create a local branch named "dev"  
* __git flow init__

Set main as the "release branch" when promted  
Set dev as "next release branch" when prometed  
Press enter for all of the other options.

## Did you fuck up?

reinitialize with this command  
* __git flow init -f__

## Using git flow

To begin on your new feature:  
* __git flow feature start feature_name__

To push your finished feature to dev:  
* __git flow feature finish feature_name__

All done! :)  
__Between starting and finish of a feature you use the git tool you want as you usually do. CLI or GUI.__

