'''
This module provide functionality 
to count lines inside project.

It's possible to specify extentions
you want to count. They go as command 
line arguments.
'''

import os
import sys


def count_with_ext(extantions: list) -> int:
    lines_count = 0
    files = os.listdir()
    while files:
        try: # just because I'm too lazy for debugging :)
            cur_file = files[0]
            files = files[1:]
            if os.path.isdir(cur_file):
                files.extend([os.sep.join((cur_file, x)) for x in os.listdir(cur_file)])
                continue
            if os.path.splitext(cur_file)[-1] in extantions:
                lines_count += len(open(cur_file).readlines())
        except Exception:
            pass

    return lines_count
         

def _test_1():
    print('line1\nline2', file=open('tmp.trash123', 'w+'))
    if count_with_ext(['.trash123']) == 2:
        print('[TEST] Passed')
    else:
        print('[TEST] Failed')
    os.remove('tmp.trash123')



def main():
    if len(sys.argv) > 1:
        if sys.argv[1] == 'test':
            _test_1()
        else:
            exts = [x for x in sys.argv[1:]]
            print('Extantions: ', exts)
            print('Total lines: ', count_with_ext(exts))

    # default extantions
    else:
        default_exts = ['.py', '.cpp']
        print('Extantions: ', default_exts)
        print('Total lines: ', count_with_ext(default_exts))


if __name__ == '__main__':
    main()
