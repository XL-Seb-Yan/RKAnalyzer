import os
import glob

# Replace 'your_directory_path' with the actual path of the directory containing the .root files
directory_path = '/eos/home-x/xuyan/RKProj/RKAnalyzer/KStarllStudy/Data/DataF_1707406646'

# Use glob to find all .root files in the directory
root_files = glob.glob(os.path.join(directory_path, '*.root'))

# Print the list of .root files
for root_file in root_files:
    print(root_file)