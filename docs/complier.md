# compli

```shell

odb -d mysql --generate-query --generate-schema myodb.hxx

```

odb 根据XXX.hxx生成
- XXX.sql
- XXX-odb.cxx
- XXX-odb.hxx
- XXX-odb.ixx

引入

```c++

#include "database.hxx" // create_database
#include "person.hxx"
#include "person-odb.hxx"

```

三个头文件


模板代码

```c++

    try {
        auto_ptr<database> db(create_database(argc, argv));

    }catch (const odb::exception& e)
    {
        cerr << e.what () << endl;
        return 1;
    }
    return 0;

```

```c++

create_database()
构造auto_ptr<database>
捕获odb::exception

```


```c++

#include <odb/database.hxx>
#include <odb/transaction.hxx>

```