# testodb


## terminal complie

termianl进入hello文件夹


[odb访问mysql数据库](https://blog.csdn.net/woaichanganba/article/details/79841356)

```shell

odb -d mysql --generate-query --generate-schema person.hxx

```

直接运行这条语句会生成会生成四个文件,如下person-odb.cxx,person-odb.hxx,person-odb.ixx,person.sql

person.sql是自动生成的建立表的sql语句
其他三个是操作数据库支持的代码
上述命令 --generate-query选项是生成数据查询支持的代码,--generate-schema选项是生成创建数据表相关的代码



```shell

g++ -c person-odb.cxx
g++ -DDATABASE_MYSQL -c driver.cxx
g++ -o driver driver.o person-odb.o -lodb-mysql -lodb

mysql --user=root --password=5Edidada --database=odb_test < person.sql

./driver --user odb_test --database odb_test #not suggest

./driver --user root --password 5Edidada --database odb_test --host 60.205.225.118

```


```shell


./driver --help
Usage: ./driver [options]
Options:
--user <name>         MySQL database user.
--password <str>      MySQL database password
--database <name>     MySQL database name.
--host <addr>         MySQL database host name or address (localhost by
                      default).
--port <integer>      MySQL database port number.
--socket <name>       MySQL database socket name.
--options-file <file> Read additional options from <file>. Each option
                      appearing on a separate line optionally followed by space
                      and an option value. Empty lines and lines starting with
                      '#' are ignored.


```


编译运行

g++ -std=c++11 -o driver test.cpp person-odb.cxx -lodb-mysql -lodb

./driver


### note
.sql file is generate


```shell

[root@localhost hello]# odb --help
Usage: odb [options] file [file ...]
Options:
--help                        Print usage information and exit.
--version                     Print version and exit.
-I <dir>                      Add <dir> to the beginning of the list of
                              directories to be searched for included header
                              files.
-D <name>[=<def>]             Define macro <name> with definition <def>.
-U <name>                     Cancel any previous definitions of macro <name>,
                              either built-in or provided with the '-D' option.
--database|-d <db>            Generate code for the <db> database.
--multi-database|-m <type>    Enable multi-database support and specify its
                              type.
--default-database <db>       When static multi-database support is used,
                              specify the database that should be made the
                              default.
--generate-query|-q           Generate query support code.
--generate-prepared           Generate prepared query execution support code.
--omit-unprepared             Omit un-prepared (once-off) query execution
                              support code.
--generate-session|-e         Generate session support code.
--generate-schema|-s          Generate the database schema.
--generate-schema-only        Generate only the database schema.
--suppress-migration          Suppress the generation of database schema
                              migration statements.
--suppress-schema-version     Suppress the generation of schema version table.
--schema-version-table <name> Specify the alternative schema version table name
                              instead of the default 'schema_version'.
--schema-format <format>      Generate the database schema in the specified
                              format.
--omit-drop                   Omit 'DROP' statements from the generated
                              database schema.
--omit-create                 Omit 'CREATE' statements from the generated
                              database schema.
--schema-name <name>          Use <name> as the database schema name.
--fkeys-deferrable-mode <m>   Use constraint checking mode <m> in foreign keys
                              generated for object relationships.
--default-pointer <ptr>       Use <ptr> as the default pointer for persistent
                              objects and views.
--session-type <type>         Use <type> as the alternative session type
                              instead of the default 'odb::session'.
--profile|-p <name>           Specify a profile that should be used during
                              compilation.
--at-once                     Generate code for all the input files as well as
                              for all the files that they include at once.
--schema <schema>             Specify a database schema (database namespace)
                              that should be assigned to the persistent classes
                              in the file being compiled.
--export-symbol <symbol>      Insert <symbol> in places where DLL export/import
                              control statements
                              ('__declspec(dllexport/dllimport)') are
                              necessary.
--extern-symbol <symbol>      If <symbol> is defined, insert it in places where
                              a template instantiation must be declared
                              'extern'.
--std <version>               Specify the C++ standard that should be used
                              during compilation.
--warn-hard-add               Warn about hard-added data members.
--warn-hard-delete            Warn about hard-deleted data members and
                              persistent classes.
--warn-hard                   Warn about both hard-added and hard-deleted data
                              members and persistent classes.
--output-dir|-o <dir>         Write the generated files to <dir> instead of the
                              current directory.
--input-name <name>           Use <name> instead of the input file to derive
                              the names of the generated files.
--changelog <file>            Read/write changelog from/to <file> instead of
                              the default changelog file.
--changelog-in <file>         Read changelog from <file> instead of the default
                              changelog file.
--changelog-out <file>        Write changelog to <file> instead of the default
                              changelog file.
--changelog-dir <dir>         Use <dir> instead of the input file directory as
                              the changelog file directory.
--init-changelog              Force re-initialization of the changelog even if
                              one exists (all the existing change history will
                              be lost).
--odb-file-suffix <suffix>    Use <suffix> to construct the names of the
                              generated C++ files.
--sql-file-suffix <suffix>    Use <suffix> to construct the name of the
                              generated schema SQL file.
--schema-file-suffix <suffix> Use <suffix> to construct the name of the
                              generated schema C++ source file.
--changelog-file-suffix <sfx> Use <sfx> to construct the name of the changelog
                              file.
--hxx-suffix <suffix>         Use <suffix> instead of the default '.hxx' to
                              construct the name of the generated C++ header
                              file.
--ixx-suffix <suffix>         Use <suffix> instead of the default '.ixx' to
                              construct the name of the generated C++ inline
                              file.
--cxx-suffix <suffix>         Use <suffix> instead of the default '.cxx' to
                              construct the name of the generated C++ source
                              file.
--sql-suffix <suffix>         Use <suffix> instead of the default '.sql' to
                              construct the name of the generated database
                              schema file.
--changelog-suffix <suffix>   Use <suffix> instead of the default '.xml' to
                              construct the name of the changelog file.
--hxx-prologue <text>         Insert <text> at the beginning of the generated
                              C++ header file.
--ixx-prologue <text>         Insert <text> at the beginning of the generated
                              C++ inline file.
--cxx-prologue <text>         Insert <text> at the beginning of the generated
                              C++ source file.
--schema-prologue <text>      Insert <text> at the beginning of the generated
                              schema C++ source file.
--sql-prologue <text>         Insert <text> at the beginning of the generated
                              database schema file.
--migration-prologue <text>   Insert <text> at the beginning of the generated
                              database migration file.
--sql-interlude <text>        Insert <text> after all the 'DROP' and before any
                              'CREATE' statements in the generated database
                              schema file.
--hxx-epilogue <text>         Insert <text> at the end of the generated C++
                              header file.
--ixx-epilogue <text>         Insert <text> at the end of the generated C++
                              inline file.
--cxx-epilogue <text>         Insert <text> at the end of the generated C++
                              source file.
--schema-epilogue <text>      Insert <text> at the end of the generated schema
                              C++ source file.
--sql-epilogue <text>         Insert <text> at the end of the generated
                              database schema file.
--migration-epilogue <text>   Insert <text> at the end of the generated
                              database migration file.
--hxx-prologue-file <file>    Insert the content of <file> at the beginning of
                              the generated C++ header file.
--ixx-prologue-file <file>    Insert the content of <file> at the beginning of
                              the generated C++ inline file.
--cxx-prologue-file <file>    Insert the content of <file> at the beginning of
                              the generated C++ source file.
--schema-prologue-file <file> Insert the content of <file> at the beginning of
                              the generated schema C++ source file.
--sql-prologue-file <file>    Insert the content of <file> at the beginning of
                              the generated database schema file.
--migration-prologue-file <f> Insert the content of file <f> at the beginning
                              of the generated database migration file.
--sql-interlude-file <file>   Insert the content of <file> after all the 'DROP'
                              and before any 'CREATE' statements in the
                              generated database schema file.
--hxx-epilogue-file <file>    Insert the content of <file> at the end of the
                              generated C++ header file.
--ixx-epilogue-file <file>    Insert the content of <file> at the end of the
                              generated C++ inline file.
--cxx-epilogue-file <file>    Insert the content of <file> at the end of the
                              generated C++ source file.
--schema-epilogue-file <file> Insert the content of <file> at the end of the
                              generated schema C++ source file.
--sql-epilogue-file <file>    Insert the content of <file> at the end of the
                              generated database schema file.
--migration-epilogue-file <f> Insert the content of file <f> at the end of the
                              generated database migration file.
--odb-prologue <text>         Compile <text> before the input header file.
--odb-prologue-file <file>    Compile <file> contents before the input header
                              file.
--odb-epilogue <text>         Compile <text> after the input header file.
--odb-epilogue-file <file>    Compile <file> contents after the input header
                              file.
--table-prefix <prefix>       Add <prefix> to table names and, for databases
                              that have global index and/or foreign key names,
                              to those names as well.
--index-suffix <suffix>       Use <suffix> instead of the default '_i' to
                              construct index names.
--fkey-suffix <suffix>        Use <suffix> instead of the default '_fk' to
                              construct foreign key names.
--sequence-suffix <suffix>    Use <suffix> instead of the default '_seq' to
                              construct sequence names.
--sql-name-case <case>        Convert all automatically-derived SQL names to
                              upper or lower case.
--table-regex <regex>         Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              table names.
--column-regex <regex>        Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              column names.
--index-regex <regex>         Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              index names.
--fkey-regex <regex>          Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              foreign key names.
--sequence-regex <regex>      Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              sequence names.
--statement-regex <regex>     Add <regex> to the list of regular expressions
                              that is used to transform automatically-derived
                              prepared statement names.
--sql-name-regex <regex>      Add <regex> to the list of regular expressions
                              that is used to transform all
                              automatically-derived SQL names.
--sql-name-regex-trace        Trace the process of applying regular expressions
                              specified with the SQL name '--*-regex' options.
--accessor-regex <regex>      Add <regex> to the list of regular expressions
                              used to transform data member names to function
                              names when searching for a suitable accessor
                              function.
--accessor-regex-trace        Trace the process of applying regular expressions
                              specified with the '--accessor-regex' option.
--modifier-regex <regex>      Add <regex> to the list of regular expressions
                              used to transform data member names to function
                              names when searching for a suitable modifier
                              function.
--modifier-regex-trace        Trace the process of applying regular expressions
                              specified with the '--modifier-regex' option.
--include-with-brackets       Use angle brackets (<>) instead of quotes ("") in
                              the generated '#include' directives.
--include-prefix <prefix>     Add <prefix> to the generated '#include'
                              directive paths.
--include-regex <regex>       Add <regex> to the list of regular expressions
                              used to transform generated '#include' directive
                              paths.
--include-regex-trace         Trace the process of applying regular expressions
                              specified with the '--include-regex' option.
--guard-prefix <prefix>       Add <prefix> to the generated header inclusion
                              guards.
--show-sloc                   Print the number of generated physical source
                              lines of code (SLOC).
--sloc-limit <num>            Check that the number of generated physical
                              source lines of code (SLOC) does not exceed
                              <num>.
--options-file <file>         Read additional options from <file> with each
                              option appearing on a separate line optionally
                              followed by space and an option value.
-x <option>                   Pass <option> to the underlying C++ compiler
                              ('g++').
-v                            Print the commands executed to run the stages of
                              compilation.
--trace                       Trace the compilation process.
--mysql-engine <engine>       Use <engine> instead of the default 'InnoDB' in
                              the generated database schema file.
--sqlite-override-null        Make all columns in the generated database schema
                              allow 'NULL' values.
--sqlite-lax-auto-id          Do not force monotonically increasing
                              automatically-assigned object ids.
--pgsql-server-version <ver>  Specify the minimum PostgreSQL server version
                              with which the generated C++ code and schema will
                              be used.
--oracle-client-version <ver> Specify the minimum Oracle client library (OCI)
                              version with which the generated C++ code will be
                              linked.
--oracle-warn-truncation      Warn about SQL names that are longer than 30
                              characters and are therefore truncated.
--mssql-server-version <ver>  Specify the minimum SQL Server server version
                              with which the generated C++ code and schema will
                              be used.
--mssql-short-limit <size>    Specify the short data size limit.

```


添加命令行参数 -DDATABASE_MYSQL

```c

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDATABASE_MYSQL")

```


