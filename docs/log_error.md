# error


```c++

====================[ Build | myodb | Debug ]===================================
/root/clion-2018.2.6/bin/cmake/linux/bin/cmake --build /root/CLionProjects/myodb/cmake-build-debug --target myodb -- -j 1
[ 33%] Building CXX object CMakeFiles/myodb.dir/main.cpp.o
In file included from /root/CLionProjects/myodb/main.cpp:4:0:
/root/CLionProjects/myodb/database.hxx:35:13: warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
 inline std::auto_ptr<odb::database>
             ^
In file included from /opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/memory:81:0,
                 from /usr/local/include/odb/database.hxx:14,
                 from /root/CLionProjects/myodb/main.cpp:1:
/opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/bits/unique_ptr.h:49:28: note: declared here
   template<typename> class auto_ptr;
                            ^
In file included from /root/CLionProjects/myodb/main.cpp:4:0:
/root/CLionProjects/myodb/database.hxx: In function ‘std::auto_ptr<odb::database> create_database(int&, char**)’:
/root/CLionProjects/myodb/database.hxx:62:3: warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
   auto_ptr<database> db (new odb::mysql::database (argc, argv));
   ^
In file included from /opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/memory:81:0,
                 from /usr/local/include/odb/database.hxx:14,
                 from /root/CLionProjects/myodb/main.cpp:1:
/opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/bits/unique_ptr.h:49:28: note: declared here
   template<typename> class auto_ptr;
                            ^
/root/CLionProjects/myodb/main.cpp: In function ‘int main(int, char**)’:
/root/CLionProjects/myodb/main.cpp:15:9: warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
         auto_ptr<database> db(create_database(argc, argv));
         ^
In file included from /opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/memory:81:0,
                 from /usr/local/include/odb/database.hxx:14,
                 from /root/CLionProjects/myodb/main.cpp:1:
/opt/rh/devtoolset-4/root/usr/include/c++/5.2.1/bits/unique_ptr.h:49:28: note: declared here
   template<typename> class auto_ptr;
                            ^
In file included from /usr/local/include/odb/database.hxx:23:0,
                 from /root/CLionProjects/myodb/main.cpp:1:
/usr/local/include/odb/traits.hxx: In instantiation of ‘struct odb::object_traits_impl<student, (odb::database_id)5u>’:
/usr/local/include/odb/database.txx:38:28:   required from ‘typename odb::object_traits<T>::id_type odb::database::persist_(T&) [with T = student; odb::database_id DB = (odb::database_id)5u; typename odb::object_traits<T>::id_type = odb::access::object_traits<student>::id_type]’
/usr/local/include/odb/database.ixx:160:35:   required from ‘typename odb::object_traits<T>::id_type odb::database::persist(T&) [with T = student; typename odb::object_traits<T>::id_type = odb::access::object_traits<student>::id_type]’
/root/CLionProjects/myodb/main.cpp:19:25:   required from here
/usr/local/include/odb/traits.hxx:177:10: error: invalid use of incomplete type ‘class odb::access::object_traits_impl<student, (odb::database_id)5u>’
   struct object_traits_impl:
          ^
In file included from /usr/local/include/odb/traits.hxx:10:0,
                 from /usr/local/include/odb/database.hxx:23,
                 from /root/CLionProjects/myodb/main.cpp:1:
/usr/local/include/odb/forward.hxx:99:11: note: declaration of ‘class odb::access::object_traits_impl<student, (odb::database_id)5u>’
     class object_traits_impl;
           ^
In file included from /usr/local/include/odb/database.hxx:632:0,
                 from /root/CLionProjects/myodb/main.cpp:1:
/usr/local/include/odb/database.txx: In instantiation of ‘typename odb::object_traits<T>::id_type odb::database::persist_(T&) [with T = student; odb::database_id DB = (odb::database_id)5u; typename odb::object_traits<T>::id_type = odb::access::object_traits<student>::id_type]’:
/usr/local/include/odb/database.ixx:160:35:   required from ‘typename odb::object_traits<T>::id_type odb::database::persist(T&) [with T = student; typename odb::object_traits<T>::id_type = odb::access::object_traits<student>::id_type]’
/root/CLionProjects/myodb/main.cpp:19:25:   required from here
/usr/local/include/odb/database.txx:38:28: error: ‘persist’ is not a member of ‘object_traits {aka odb::object_traits_impl<student, (odb::database_id)5u>}’
     object_traits::persist (*this, obj);
                            ^
/usr/local/include/odb/database.txx:40:67: error: no type named ‘reference_cache_traits’ in ‘struct odb::object_traits_impl<student, (odb::database_id)5u>’
     typename object_traits::reference_cache_traits::position_type p (
                                                                   ^
/usr/local/include/odb/database.txx:44:52: error: no type named ‘reference_cache_traits’ in ‘struct odb::object_traits_impl<student, (odb::database_id)5u>’
     object_traits::reference_cache_traits::persist (p);
                                                    ^
/usr/local/include/odb/database.txx:40:67: error: no type named ‘reference_cache_traits’ in ‘struct odb::object_traits_impl<student, (odb::database_id)5u>’
     typename object_traits::reference_cache_traits::position_type p (
                                                                   ^
/usr/local/include/odb/database.txx:46:30: error: ‘id’ is not a member of ‘object_traits {aka odb::object_traits_impl<student, (odb::database_id)5u>}’
     return object_traits::id (obj);
                              ^
gmake[3]: *** [CMakeFiles/myodb.dir/main.cpp.o] 错误 1
gmake[2]: *** [CMakeFiles/myodb.dir/all] 错误 2
gmake[1]: *** [CMakeFiles/myodb.dir/rule] 错误 2
gmake: *** [myodb] 错误 2


```