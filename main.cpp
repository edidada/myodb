#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "database.hxx" // create_database

#include "myodb.hxx"
#include "myodb-odb.hxx"

using namespace std;
using namespace odb;

int main(int argc, char* argv[]) {
    unsigned long test_id, joe_id;
    try {
//        db information is in argv
        auto_ptr<database> db(create_database(argc, argv));
        student test("1","2",29);
        student make("5","4","3",19);
        transaction t(db->begin ());
        db->persist(test);
        t.commit ();
    }catch (const odb::exception& e)
    {
        cerr << e.what () << endl;
        return 1;
    }
    return 0;
}