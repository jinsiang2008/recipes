1. `git ls-files | xargs cloc`: Count lines of code in git repo
2. `twistd -n ftp -r ./`: FTP server on port 2121
3. `watch -n 0 <command>`: run any command every 0.1s
4. `rsync -abviuzP src/ dest/` from https://superuser.com/a/547316/173890
    - `-i` turns on the itemized format, which shows more information than the default format
    - `-b` makes rsync backup files that exist in both folders, appending `~` to the old file. You can control this suffix with `--suffix .suf`
    - `-u` makes rsync transfer skip files which are newer in dest than in src
    - `-z` turns on compression, which is useful when transferring easily-compressible files over slow links
    - `-P` turns on `--partial` and `--progress`
    - `--partial` makes rsync keep partially transferred files if the transfer is interrupted
    - `--progress` shows a progress bar for each transfer, useful if you transfer big files
5. netstat: -l/--listening, -a/--all, -t/--tcp, -u/--udp, -n/--numeric
    - `netstat -atn` check listening TCP ports
    - `netstat -atn` check listening UCP ports
    - `netstat -atun` check listening on both ports
