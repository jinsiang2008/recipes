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
6. `cat /proc/sys/kernel/random/entropy_avail`: Check entropy pool size (below 200 is not good)
7. `curl -w "TCP handshake: %{time_connect}， SSL handshake: %{time_appconnect}\n" -so /dev/null https://www.google.com`
    - HTTP time: TCP handshake
    - HTTPS time: TCP handshake + SSL handshake
8. `pv`: "pipe viewer", show stats on data goi ng through a pipe
9. `sed s/foo/bar/g file.txt`, `foo` can be a regular expression
    - GNU and BSD sed behaviors differently in `-i`, so [always use](https://stackoverflow.com/a/22084103/1035859) `-i.bak`
    - `sed -n 12p` print 12th line, `sed -n 5, 30p` print liens 5-30. `-n` suppresses output so only `p`'s part gets printed 
    - `sed 5d` delete 5th line, `sed /foo/d` delete lines matching `/foo/`
    - `sed '/foo/a bar'` append 'bar' after lines containing 'foo'
10. [awk](https://coolshell.cn/articles/9070.html): `docker ps | awk {'print $1'}` print first column container ID
    - `$NF` for total number, last column