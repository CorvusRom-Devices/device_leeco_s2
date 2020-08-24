cd frameworks/av
git remote add wfd https://github.com/merser2005/android_frameworks_av
git fetch wfd
git cherry-pick 06efe44d03ed988a7c68ab5d7b3b13559ba3a1c1
git remote rm wfd
cd ../..
