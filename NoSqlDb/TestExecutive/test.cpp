/////////////////////////////////////////////////////////////////////
// test.cpp - Demonstrate Project 1 Key Value Database             //
//                                                                 //
//															       //
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include "../XmlDocument/XmlDocument/XmlDocument.h"
#include "../XmlDocument/XmlElement/XmlElement.h"
#include "../CppProperties/CppProperties.h"
#include "../Convert/Convert.h"
#include "../StrHelper.h"
#include "../NoSqlDb/NoSqlDb.h"

using StrData = std::string;
using Key = NoSqlDb<StrData>::Key;
using Keys = NoSqlDb<StrData>::Keys;
using intData = int;
using namespace XmlProcessing;
using SPtr = std::shared_ptr<AbstractXmlElement>;

void display(NoSqlDb<StrData> db);
bool check(bool);
void displayKeys(std::vector<std::string> vec);
Element<StrData> addElement(std::string name, std::string category, std::string description, std::string timeDate, std::string data);
NoSqlDb<StrData> db;
void DemonstrateRequirement2();
void DemonstrateRequirement3();
void DemonstrateRequirement4();
void DemonstrateRequirement5();
void DemonstrateRequirement6();
void DemonstrateRequirement7();
void DemonstrateRequirement8();
void DemonstrateRequirement9();
void DemonstrateRequirement12();

//Main of Test Stub
int main()
{
	std::cout << "Demonstrating Project #1: KEY/VALUE DATABASE\n\n";
	std::cout << "Shall be implemented in C++ using STL in Visual Studio\n ";
	std::cout << "=================================\n";

	std::cout << "Requirement 2 : Shall Provide the template Class to store in-memory database\n";
	std::cout << "=================================\n";
	DemonstrateRequirement2();
	std::cout << "\n**Note that here child is getting inserted only if it is the Key to some other element\n";

	std::cout << "\n\nRequirement 3 : Addition and deletion of Key/Value Pairs.";
	std::cout << "\n =================================\n";
	DemonstrateRequirement3();

	std::cout << "\n  Requirement 4: Shall support editing of values including the addition and/or deletion of relationships, editing text metadata, and replacing an existing value's instance with a new instance. Editing of keys is forbidden";
	std::cout << "\n =================================\n\n";
	DemonstrateRequirement4();

	std::cout << "\n Requirement 5: On Command Persist Database contents to XML file";
	std::cout << "\n =================================\n\n";
	DemonstrateRequirement5();

	std::cout << "\n Requirement 6: Shall accept a positive time interval or number of writes after which the database contents are persisted. This scheduled 'save' process shall continue until cancelled. By default, timed saving is turned off.";
	std::cout << "\n =================================\n\n";
	DemonstrateRequirement6();

	std::cout << "\n Requirement 7: Queries";
	std::cout << "\n =================================\n";
	DemonstrateRequirement7();

	std::cout << "\n Requirement 8";
	std::cout << "\n =================================\n";
	DemonstrateRequirement8();

	std::cout << "\n Requirement 9";
	std::cout << "\n =================================\n";
	DemonstrateRequirement9();

	std::cout << "\n Requirement 12: Support Regular expressions for queries";
	std::cout << "\n =================================\n";
	DemonstrateRequirement12();
}

void DemonstrateRequirement2()
{
	std::cout << "2.1 Creating and saving NoSqlDb elements with String data\n";
	Element<StrData> elem1 = addElement("Convert", "library", "(de)serializes objects of type T (from)to strings", "01/20/2017 03:40", "Data Conversion");
	Element<StrData> elem2 = addElement("CppProperties", "library", "Defines read/write and read only properties", "01/21/2017 05:45", "Acts like getters and setters");
	
	Element<StrData> elem4;
	elem4.name = "NoSqlDb";
	elem4.category = "Database";
	elem4.description = "In-memory Database";
	elem4.timeDate = "01/23/2017 13:50";
	elem4.data = "database";
	elem4.addChildToElement(db, "Convert");
	std::cout << "\nTrying to insert child 'XYZ' to the element 4.\n(NOTE: XYZ is not the KEY of any element in database)";
	//xyz is not the key ofany element in Database. So xyz wont be added
	elem4.addChildToElement(db, "XYZ");
	elem4.addChildToElement(db, "CppProperties");
	std::cout << "\nInserting element in in-memory database...";
	db.add(elem4.name, elem4);

	Element<StrData> elem6;
	elem6.name = "TestExecutive";
	elem6.category = "Test File";
	elem6.description = "Demonstration of project";
	elem6.timeDate = "1/26/2017 8:00";
	elem6.data = "Test file";
	elem6.addChildToElement(db, "Convert");
	elem6.addChildToElement(db, "CppProperties");
	elem6.addChildToElement(db, "NoSqlDb");
	db.add(elem6.name, elem6);
	std::cout << "\nInserting element in in-memory database...";
	display(db);

	std::cout << "\n2.2 Creating and saving NoSqlDb elements with int data";
	NoSqlDb<int>idb;
	Element<intData> ielem3;
	ielem3.name = "IGate";
	ielem3.category = "Consultancy";
	ielem3.data = 3;
	ielem3.description = "Integer data";
	ielem3.timeDate = "03/25/2017 12:00";
	idb.add(ielem3.name, ielem3);
	for (Key key : idb.keys())
		std::cout << "\n " << key << ":" << idb.value(key).show();
}

void DemonstrateRequirement3()
{
	bool autoPersist = false;
	std::cout << "\n 3.1. Adding element with Key: XMLDocument\n Name: XMLDocument";
	Element<StrData> elem5;
	elem5.name = "XMLDocument";
	elem5.category = "Container";
	elem5.description = "Container of XML element nodes";
	elem5.timeDate = "01/31/2017 12:00";
	elem5.data = "Container containg toXml and fromXml functions";
	db.add(elem5.name, elem5);

	std::cout << "\nDatabase after Inserting data:";
	display(db);
	std::cout << "\n3.2. Deleting element with key 'NoSqlDb' from database\n\n";
	db.delete_("NoSqlDb");
	//check function for auto persisting data
	check(autoPersist);
	std::cout << "\n\nDatabase after deleting the element from database\n";
	display(db);

	std::cout << "Inserting NoSqlDb again to the Database for maintaining records";
	Element<StrData> elem7;
	elem7.name = "NoSqlDb";
	elem7.category = "Database";
	elem7.description = "In - memory database operations using STL Container unordered map";
	elem7.timeDate = "01/31/2017 12:00";
	elem7.data = "Is templated on data part, to store any kind of data";
	elem7.childrenList.push_back("Convert");
	elem7.childrenList.push_back("CppProperties");
	db.add(elem7.name, elem7);
	check(autoPersist);

}

void DemonstrateRequirement4()
{
	std::cout << "\n4.1. Inserting child 'XMLDocument' to element 'NoSqlDb'\n";
	Element<StrData> &elem = db.value("NoSqlDb");
	elem.addChildToElement(db, "XMLDocument");

	std::cout << "\n Inserting child 'TestExecutive' to element 'NoSqlDb'\n";
	elem.addChildToElement(db, "TestExecutive");
	display(db);
	//deleting child 'TestExecutive' from the 'NoSqlDb' element
	std::cout << "\n4.2. Deleting a child 'TestExecutive' from the 'NoSqlDb' element";
	for (std::vector<std::string>::iterator it = elem.childrenList.begin(); it != elem.childrenList.end(); ++it)
		if (*it == "TestExecutive") {
			elem.childrenList.erase(it);
			break;
		}
	display(db);
	std::cout << "\n4.3. Editing text meta data for element TestExecutive\n";
	Keys keys = db.keys();
	for (Key key : keys)
		if (key == "TestExecutive")
		{
			Element<StrData> &elem = db.value(key);
			elem.data = "Text data is updated";
		}
	display(db);
	
	std::cout << "\n4.4. Replacing existing values instance of 'TestExecutive' with new instance\n";
	Element<StrData> &elem1 = db.value("TestExecutive");
	Element<StrData> newElem;
	newElem.name = "TestExecutive";
	newElem.category = "new Text Executive Category";
	newElem.description = "new Description";
	newElem.timeDate = "02/02/2017 12:20";
	newElem.data = "Text data is updated";
	newElem.addChildToElement(db, "NoSqlDb");
	elem1 = newElem;
	display(db);
	std::cout << "\n4.5 Editing of keys is forbidden";
	db.editKey("NoSqlDb");
}

void DemonstrateRequirement5()
{
	NoSqlDb < std::string>db1;
	Element<StrData> elem1 = addElement("ABCD", "library", "(de)serializes objects of type T (from)to strings", "01/27/2017 12:00", "Data Conversion");
	db1.add(elem1.name, elem1);

	std::cout << "\n5.1. Persisting the data to XML file at Location 'XML Data/data.xml'";
	db.toXML("../XML Data/data.xml");

	std::cout << "\n5.2. Reading the data from XMl & Augmenting data to db1";
	std::cout << "\nDisplaying db1 before augmenting";
	display(db1);

	//augmenting to existing in-mem database
	std::cout << "\nDisplaying db2 after augmenting";
	db1.fromXML("../XML Data/data.xml");
	display(db1);

}

void DemonstrateRequirement6()
{
	bool autoPersist = true;
	std::cout << "\nAuto persist set ON";
	//Data will be auto persisted only if number of writes is 8 and Auto persist mode is set ON

	check(autoPersist);
	std::cout << "\nAdding Dummy data to Database to demonstrate Queries\n";
	Element<StrData> newEl;
	for (int i = 0; i < 3; i++)
	{
		newEl.name = "str" + std::to_string(i);
		newEl.category = "dummy on category" + i;
		newEl.description = "dummy description" + i;
		newEl.timeDate = "02/05/2017 11:51";
		newEl.data = "dummyon data" + i;
		std::cout << "\nDummy Element inserted";
		db.add(newEl.name, newEl);
		check(autoPersist);
	}
	display(db);

}

void DemonstrateRequirement7()
{
	std::cout << "\n7.1. The value of 'key NoSqlDb'.";
	Element<std::string> el1 = db.value("NoSqlDb");
	
	std::cout << "\nValue:\nName: " << el1.name << "\nCategory: " << el1.category << "\nDescription: " << el1.description << "\nChildList: ";
	for (std::vector<std::string> ::iterator it = el1.childrenList.begin(); it != el1.childrenList.end(); it++)
		std::cout << "\n" << *it;
	std::cout << "\nData: " << el1.data;

	std::cout << "\n7.2. The children of key 'NoSqlDb'\nChildren: ";
	std::vector<std::string>result = db.executeQuery(db.childrenType, "NoSqlDb");
	for (int i = 0; i < result.size(); i++)
		std::cout << "\n" << result[i];
	std::cout << "\n7.3. All keys that match Pattern 'str'\n";
	std::cout << "\nFinding keys with : 'str'";
	std::cout << "\nKeys matching specified pattern:\n";
	std::vector<std::string> result1 = db.executeQuery(db.keyType, "str");

	for (int i = 0; i < result1.size(); i++)
		std::cout << "\n" << result1[i];
	std::cout << "\n7.4. All keys which match patten '' ->Defaults to all keys";
	result1 = db.executeQuery(db.keyType, "");
	for (int i = 0; i < result1.size(); i++)
		std::cout << "\n" << result1[i];

	std::cout << "\n7.5. All keys that contain string 'Con' in their item name.\nKeys:\n";
	std::vector<std::string> result2 = db.executeQuery(db.nameType, "Con");
	for (int i = 0; i < result2.size(); i++)
		std::cout << "\n" << result2[i];
	std::cout << "\n7.6. All keys that contain string 'new' in their category name.\n";
	std::vector<std::string> result3 = db.executeQuery(db.categoryType, "new");
	for (int i = 0; i < result3.size(); i++)
		std::cout << "\n" << result3[i];

	std::cout << "\n7.7. All keys that written in time interval 01/31/2017 10:00 and 02/07/2017 17:00";
	result3 = db.executeQuery(db.datetimeType,"01/31/2017 10:00","02/07/2017 17:00");
	for (int i = 0; i < result3.size(); i++)
		std::cout << "\n" << result3[i];

	std::cout << "\n7.7. All keys that written in time interval 01/31/2017 10:00 and ''";
	result3 = db.executeQuery(db.datetimeType, "01/31/2017 10:00","");
	for (int i = 0; i < result3.size(); i++)
		std::cout << "\n" << result3[i];


	std::cout << "\n7.8. All keys that contain string 'at' in their data section.\nKeys: ";
	std::vector<std::string> result4 = db.executeQuery(db.stringDataType, "at");
	for (int i = 0; i < result4.size(); i++)
		std::cout << "\n" << result4[i];
}

void DemonstrateRequirement8()
{
	//compound queries
	std::cout << "\n8. All keys that match Pattern 'str' in key part and  'at' in their data section";
	std::vector<std::string> result1 = db.executeQuery(db.keyType, "str");
	std::vector<std::string> result2 = db.executeQuery(db.stringDataType, "at");

	std::vector<std::string> result4 = db.CompoundQuery(true, result1, result2);
	for (int i = 0; i < result4.size(); i++)
		std::cout << "\n" << result4[i];


}

void DemonstrateRequirement9()
{
	std::cout << " \n9. All keys with pattern 'str' in key string or having 'new' in their category name";
	std::vector<std::string> resultSet;
	std::vector<std::string> result1 = db.executeQuery(db.keyType, "str");
	std::vector<std::string> result2 = db.executeQuery(db.categoryType, "new");

	std::vector<std::string> result4 = db.CompoundQuery(false, result1, result2);
	for (int i = 0; i < result4.size(); i++)
		std::cout << "\n" << result4[i];

}

void DemonstrateRequirement12()
{
	//Demonstrating query using Regular expression to check all the keys which has string 'new' in category name

	std::cout << "\nDemonstrating Querrying using Regular exressions";
	std::vector<std::string> result3 = db.executeQuery(db.categoryType, "new");
	for (int i = 0; i < result3.size(); i++)
		std::cout << "\n"<<result3[i];
	std::cout << "\n";
}

Element<StrData> addElement(std::string name, std::string category, std::string description, std::string timeDate, std::string data)
{
	bool autoPersist=false;
	Element<StrData> element;
	element.name = name;
	element.category = category;
	element.description = description;
	element.timeDate = timeDate;
	element.data = data;

	std::cout << "\nInserting element in in-memory database...";
	db.add(element.name, element);
	//checking if autopersists mode should be turned on
	check(autoPersist);
	return element;
}

void displayKeys(std::vector<std::string> vec)
{
	for (std::vector<std::string> ::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << "\n" << *it;
	}
}

void display(NoSqlDb<std::string> db)
{
	//Displaying the database elements

	std::cout << "\n  Retrieving elements from NoSqlDb<string>";
	std::cout << "\n ------------------------------------------\n";

	std::cout << "\n  size of db = " << db.count() << "\n";
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
	std::cout << "\n\n";
}

bool check(bool autoPersist)
{
	//checks if number of writes exceeds 8 and auto persist mode is set on
	static int count=0;
	count++;
	if ((count > 8) && autoPersist) {
		db.toXML("../XML Data/data.xml");
		std::cout << "----AUTO PERSIST successs";
		count = 0;
		return true;
	}
	return false;
}
