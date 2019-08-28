"""
    Calculates size of repository.
    Takes .gitignore into consideration.
"""
import os
from gitignore_parser import parse_gitignore
import argparse



class GitError(Exception):
    pass


class GitIgnoreNotExist(GitError):
    pass


class GitNotInitialized(GitError):
    pass


class RepositoryInfo:
    """
    Gether information 
    about git repository
    of its subdirectory

    Raises:
        GitNotInitialized: [description]
        GitIgnoreNotExist: [description]
    """
    def __init__(self, repo_path=os.getcwd(), target_dir=None):
        """
        Keyword Arguments:
            repo_path {str} -- path to git repository (default: {os.getcwd()})
            target_dir {str} -- relative path to subdirectory to examine (default: {None})
        
        Raises:
            GitNotInitialized: raised if git is not initialized by that path
        """
        assert os.path.exists(repo_path) and os.path.isdir(repo_path)
        if not os.path.exists(os.path.join(repo_path, '.git')):
            raise GitNotInitialized
        self.target_dir = os.path.join(repo_path, target_dir) if target_dir is not None else repo_path
        self.path = repo_path  
        self.repo_size, self.num_of_files = self.__calculate_repo_size()


    def __calculate_repo_size(self):
        """
        Calculates size of the repo.
        
        Returns:
            int -- size of repository in bytes
            int -- number of files in repository
        """

        # getting gitignore matcher
        gitignore_path = os.path.join(self.path, '.gitignore')
        if not os.path.exists(gitignore_path):
            raise GitIgnoreNotExist
        in_gitignore = parse_gitignore(gitignore_path)

        # list files in root 
        # with prepended repo path
        files = [os.path.join(self.target_dir, file) for file in os.listdir(self.target_dir)]
        count = 0
        repo_size = 0
        for file in files:
            if in_gitignore(file):
                continue
            if os.path.isdir(file):
                # save files in the folder
                # prepending with folder path
                files.extend(os.path.join(file, inner_file) for inner_file in os.listdir(file))
            else:
                count += 1
                repo_size += os.path.getsize(file)
        return repo_size, count
            

def format_size(size: int) -> str:
    units = ['b', 'Kb', 'Mb', 'Gb']
    unit_idx = 0
    while unit_idx != len(units):
        if size / 1024 < 1:
            break
        size /= 1024
        unit_idx += 1
    return '{:.2f}'.format(size) + ' ' + units[unit_idx]


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--subdir',
        help='subdir to examine',
        required=False,
        default=None
    )
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = parse_args()
    ri = RepositoryInfo(target_dir=args.subdir)
    formated_size = format_size(ri.repo_size)
    print('Repository size: {}'.format(formated_size))
    print('Number of files in repository: {}'.format(ri.num_of_files))
    