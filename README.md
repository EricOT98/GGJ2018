# GGJ2018
The Global Game Jam 2018

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Git Methodology
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
git checkout <feature-branch>
git pull
git checkout <release-branch>
git pull
git merge --no-ff <feature-branch>
git push

##If you want to do relese
//git tag -a branch-<feature-branch> -m "Merge <feature-branch> into <release-branch>"
//git push origin branch-<feature-branch>

##Delete the branch after its done
##Delete local
git branch -d <feature-branch>
##Delete remote
git push origin :<feature-branch>

##if remote sstill appear after deletion
git branch -r <feature-branch> //Do this if the branch still appears in git branch -a remotes/
or use
git remote prune origin //Removes all stale branchs

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Git cheat sheet
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
##New branch
git checkout -b <branch_name>

##Go to branch
git checkout <branch_name>

##MERGING
git checkout <branch_name>
git add .
git commit -m "Commit name"
git pull origin master --rebase

##If merge errors
##After fixing merge
git add .
git rebase --continue

##All merge conflicts done
git checkout master
git merge <branch_name>
##ALWAYS ASK THE PROJECT MEMBERS BEFORE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
git push origin master