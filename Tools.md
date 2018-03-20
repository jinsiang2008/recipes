## CLion
+ Multiple cursor: <kbd>Alt</kbd> + <kbd>Shift</kbd> + mouse click
+ Dash: <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>D</kbd>

## VSCode
+ <kbd>Ctrl</kbd> + <kbd>Tab</kbd> to switch tabs
+ Multiple cursor: <kbd>Alt</kbd> + <kbd>Shift</kbd> + mouse click
+ <kbd>⌘</kbd> + Up/Down to go to head/end of file
+ <kbd>⌘</kbd> + Left/Right to go to first/last character of line
+ <kbd>⌘</kbd> + <kbd>Shift</kbd> + <kbd>N</kbd> to open a new window
+ <kbd>Ctrl</kbd> + <kbd>G</kbd>: go to line
+ <kbd>⌘</kbd> + <kbd>Shift</kbd> + <kbd>k</kbd> to delete current line
+ `"editor.minimap.enabled": false`: to disable minimap

## psql
+ `\l` or `\list`: list all databases
+ `\c db_name`: connect to database
+ `\q`: disconnect
+ `\conninfo`
+ `\dt`: describe tables
+ `\d table_name`: describle table schema, `\d+` for more
+ `\dF`: describe full text flag, `dF+` for more detailed info


## sqlite3
+ `.schema`: Print the database structure
+ `.explain on`: Turn on column names on query results`

## Chrome
+ <kbd>Shift</kbd> + <kbd>fn</kbd> + <kbd>Delete</kbd> Delete address bar suggestion

# Supervisord
```
# /etc/supervisor/conf.d/*.conf
[program:test1]
command=python test1.py
directory=/path/to/test1_dir
user=wilbeibi
autorestart=true
redirect_stderr=true
stdout_logfile=/var/log/test1.log
```

## Alfred workflows
+ `dash python3: os.path`

## Emoji
🛢️ 📰 💾 🖥️ 📱 💣 🚚 🚢 🗿 🚀 🏄 🔧 ☕️ 🦊

## Mac tools
+ mac2imgur
+ Mac 10.12 不允许第三方来源的app安装了，要`sudo spctl --master-disable`
+ Monodraw: ASCII diagram for illustration, banners

## ZSH
+ `cd /u/l/b`: path expansion
+ `cd site1 site2`: path replacement, if you were in /srv/www/site1/current/log, it will go to /srv/www/site2/current/log via this command
+ `ls -l **/*.log`: extened globbing, **/ = recursive
+ `zmv '(*).txt' 'template_$1.html'`: rename files
+ `ls -l zsh_demo/**/*(. Lm-2 mh-1 om)`: ls files under zsh_demo recursively, `Lm-2` for less than 2mb (similarly, `Lm+30` for over 30mb, m for megabytes, k for kilobytes, or nothing for just bytes), `mh-1` for files modified in the last hour (M for Months, w for weeks, h for hours, m for minutes, and s for seconds), `om` to o(rder) by modification date, o for most recent, O vise vesa, m for modifcaion date, or L to sort by size.
+ <kbd>Ctrl</kbd> + <kbd>X</kbd> + <kbd>Ctrl</kbd> + <kbd>E</kbd>  to edit long command

+ [Master Your Z Shell with These Outrageously Useful Tips](http://reasoniamhere.com/2014/01/11/outrageously-useful-tips-to-master-your-z-shell/)

## Mise
+ [My Diigo Programming Notes](https://www.diigo.com/outliner/dzi0kh/Programming?key=a7q47wq9b2)
