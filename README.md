# NoSqlDatabase, C++, Visual Studio.

Purpose:

There is currently a lot of technical interest in "Big Data". Extreme examples are: data
collection and analyses from the Large Hadron Collider, the Sloan Sky Survey, analyses of Biological Genomes, measuring weather patterns, collecting data for global climate models, and analyzing client interactions in social networks.
Conventional SQL databases are not well suited for these kinds of applications. While they have worked very well for many business applications and record keeping, they get overwhelmed by massive streams of data. Developers are turning to "noSQL" databases like MongoDB, couchDB, Redis, and Big Table to handle massive data collection and analyses.
In this project I have created my own in momory key/value non SQL database.

Features of Database -  

1. It is a in-memory database built using C++ Standard Template Libraries.
2. NoSQLDB is a template class providing a key/value in-memory database where each value consist of -
  
  ◦ Metadata:
    ▪ An item name string
    ▪ A category name string
    ▪ A text description of the item
    ▪ A time-date string recording the date and time the value was written to the database.
    ▪ a finite number (possibly zero) of child relationships with other values. Each element of the child relationships collection is the key of another item in the database. Any item holding a key in this collection is the parent of the element accessed by the key.
  
  ◦ An instance of the template type1. This might be a string, a container of a set of values of the same type, or some other collection of data captured in some, perhaps custom, data structure.

![nosqldb](https://user-images.githubusercontent.com/24962915/35676068-62555490-0718-11e8-852d-3169f2042a16.JPG)

3. Database supports addition and deletion of Key/Valye Pairs and also allows editing the values including addition and/or deletion of relationships, editing metadata, and replacing the existing value's instance with a new instance. Editing of Keys is forbidden.





