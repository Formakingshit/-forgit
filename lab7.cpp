#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>
#include <iomanip> 
#include <fstream>
#include <typeinfo>    

using namespace std;

/*----------------------------------------------------*/

enum saleType { Box = 1, Bouquet, Single };

/*----------------------------------------------------*/

class Date {
protected:
  int dateYear;
  int dateWeek;
public:
  Date();

  void set_dateYear(int year) {
    this->dateYear = year;
  }

  void set_dateWeek(int week) {
    this->dateWeek = week;
  }

  int get_dateYear() {
    return this->dateYear;
  }

  int get_dateWeek() {
    return this->dateWeek;
  }

  virtual void Show() {
    cout << "Date year: " << this->get_dateYear()
      << ". Date week: " << this->get_dateWeek() << endl;
  }

  friend ostream& operator<<(ostream& os, const Date& dt);

};

Date::Date() {
  this->set_dateYear(rand() % 2017 + 1);
  this->set_dateWeek(rand() % 4 + 1);
}

ostream& operator<<(ostream& os, const Date& dt)
{
  //os << "dateYear    dateWeek " << endl;
  os.width(5);
  os << dt.dateYear;
  os.width(10);
  os << dt.dateWeek;
  return os;
}

class Flower {
protected:
  string flowerName;
  string flowerColor;

  char* flowerName_char;
  char* flowerColor_char;

public:
  Flower();

  void set_flowerName(string name) {
    this->flowerName = name;
  }

  void set_flowerColor(string color) {
    this->flowerColor = color;
  }

  /*-----------------------CHAR---------------------------*/
  void set_flowerName_char(char* flowerName_char_n) {
    flowerName_char = new char[strlen(flowerName_char_n) + 1];
    strcpy(this->flowerName_char, flowerName_char_n);
  }

  void set_flowerColor_char(char* flowerColor_char_n) {
    flowerColor_char = new char[strlen(flowerColor_char_n) + 1];
    strcpy(this->flowerColor_char, flowerColor_char_n);
  }
  /*-----------------------CHAR---------------------------*/


  string get_flowerName() {
    return this->flowerName;
  }

  string get_flowerColor() {
    return this->flowerColor;
  }

  virtual void Show() {
    cout << "Flower name: " << this->get_flowerName()
      << ". Flower color: " << this->get_flowerColor() << endl;
  }

  friend ostream& operator<<(ostream& os, const Flower& flower_n);

};

ostream& operator<<(ostream& os, const Flower& flower_n)
{
  //os << "flowerName      flowerColor " << endl;
  os.width(8);
  os << flower_n.flowerName;
  os.width(14);
  os << flower_n.flowerColor;
  return os;
}

Flower::Flower() {
  int x;
  string name;
  string color;

  char* name_char;
  char* color_char;

  x = rand() % 5 + 1;

  switch (x) {
  case 1: {
    name = "Anemone";
    name_char = new char[strlen("Ageratum") + 1];
    strcpy(name_char, "Ageratum");
  } break;
  case 2: {
    name = "Amaryllis";
    name_char = new char[strlen("Amaryllis") + 1];
    strcpy(name_char, "Amaryllis");
  } break;
  case 3: {
    name = "Aster";
    name_char = new char[strlen("Aster") + 1];
    strcpy(name_char, "Aster");
  } break;
  case 4: {
    name = "Campanula";
    name_char = new char[strlen("Campanula") + 1];
    strcpy(name_char, "Campanula");
  } break;
  case 5: {
    name = "Sakura";
    name_char = new char[strlen("Sakura") + 1];
    strcpy(name_char, "Sakura");
  } break;
  default: {
    name = "Roza";
    name_char = new char[strlen("Roza") + 1];
    strcpy(name_char, "Roza");
  }
  }

  x = rand() % 5 + 1;
  switch (x) {
  case 1: {
    color = "Yellow";
    color_char = new char[strlen("Yellow") + 1];
    strcpy(color_char, "Yellow");
  } break;
  case 2: {
    color = "Blue";
    color_char = new char[strlen("Blue") + 1];
    strcpy(color_char, "Blue");
  } break;
  case 3: {
    color = "Red";
    color_char = new char[strlen("Red") + 1];
    strcpy(color_char, "Red");
  } break;
  case 4: {
    color = "Green";
    color_char = new char[strlen("Green") + 1];
    strcpy(color_char, "Green");
  } break;
  case 5: {
    color = "Grey";
    color_char = new char[strlen("Grey") + 1];
    strcpy(color_char, "Grey");
  } break;
  default: {
    color = "White";
    color_char = new char[strlen("White") + 1];
    strcpy(color_char, "White");
  }
  }



  /*---------------------------STRING--------------------------------------------*/


  this->set_flowerName(name);
  this->set_flowerColor(color);


  /*---------------------------CHAR--------------------------------------------*/


  this->set_flowerName_char(name_char);
  this->set_flowerColor_char(color_char);


  /*---------------------------------------------------------------------------*/


}

class FlowerItem : virtual public Flower {
protected:

  string flowerItemTypeSaleType;
  int flowerItemPrice;


  char* flowerItemTypeSaleType_Char;

public:
  FlowerItem();

  void set_flowerTypeSaleType(string saleType) {
    this->flowerItemTypeSaleType = saleType;
  }
  /*-----------------------CHAR---------------------------*/

  void set_flowerTypeSaleType_Char(char* flowerItemTypeSaleType_Char_n) {
    flowerItemTypeSaleType_Char = new char[strlen(flowerItemTypeSaleType_Char_n) + 1];
    strcpy(this->flowerItemTypeSaleType_Char, flowerItemTypeSaleType_Char_n);
  }
  /*-----------------------CHAR---------------------------*/
  void set_flowerPrice(int price) {
    this->flowerItemPrice = price;
  }

  void Show() {
    Flower::Show();
    cout << "Flower Item Type Sale Type: " <<
      flowerItemTypeSaleType << ". Flower Item Price: " << flowerItemPrice << endl;
  }

  void operator = (FlowerItem FlowerItem_n) {
    this->flowerItemTypeSaleType = FlowerItem_n.flowerItemTypeSaleType;
    this->flowerItemPrice = FlowerItem_n.flowerItemPrice;
  }
  friend ostream& operator<<(ostream& os, const FlowerItem& FlowerItem_n);
};



ostream& operator<<(ostream& os, const FlowerItem& FlowerItem_n)
{
  //os << "flowerName     flowerColor   TypeSaleType    Flower Price " << endl;
  os << (Flower&)FlowerItem_n;
  os.width(14);
  os << FlowerItem_n.flowerItemTypeSaleType;
  os.width(14);
  os << FlowerItem_n.flowerItemPrice;
  return os;
}

FlowerItem::FlowerItem() {
  int x;
  string flowerSaleType;
  saleType typeS;

  char* flowerSaleType_Char;

  x = rand() % 3 + 1;

  switch (x) {
  case Box: {
    flowerSaleType = "Box";
    flowerSaleType_Char = new char[strlen("Box") + 1];
    strcpy(flowerSaleType_Char, "Box");
  } break;
  case Bouquet: {
    flowerSaleType = "Bouquet";
    flowerSaleType_Char = new char[strlen("Bouquet") + 1];
    strcpy(flowerSaleType_Char, "Bouquet");
  } break;
  case Single: {
    flowerSaleType = "Single";
    flowerSaleType_Char = new char[strlen("Single") + 1];
    strcpy(flowerSaleType_Char, "Single");
  } break;
  default: {
    flowerSaleType = "Single";
    flowerSaleType_Char = new char[strlen("Single") + 1];
    strcpy(flowerSaleType_Char, "Single");
  }
  }


  /*---------------------------STRING--------------------------------------------*/


  this->set_flowerTypeSaleType(flowerSaleType);
  this->set_flowerPrice(rand() % 100 + 1);


  /*---------------------------CHAR--------------------------------------------*/


  /*this->set_flowerTypeSaleType_Char(flowerSaleType_Char);
  this->set_flowerPrice(rand() % 100 + 1);*/


  /*---------------------------------------------------------------------------*/

}

class consignmentItem : virtual public FlowerItem {
protected:
  int count;
public:
  consignmentItem();
  void set_consignmentItemCount(int count_n) {
    this->count = count_n;
  }

  int get_consignmentItemCount() {
    return this->count;
  }

  void Show() {
    FlowerItem::Show();
    cout << "Consignment Item count: " << this->get_consignmentItemCount() << endl;
  }

  void operator = (consignmentItem consignmentItem_n) {
    this->count = consignmentItem_n.count;
  }
  friend ostream& operator<<(ostream& os, const consignmentItem& consignmentItem_n);
};

ostream& operator<<(ostream& os, const consignmentItem& consignmentItem_n)
{

  //os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count" << endl;
  os << (FlowerItem&)consignmentItem_n;
  os.width(16);
  os << consignmentItem_n.count;
  return os;
}

consignmentItem::consignmentItem() {
  this->set_consignmentItemCount(rand() % 1500 + 1);
}

class DeliveryItem : virtual public consignmentItem {
protected:
  Date ADelivery;
  int deliveryPrice;
public:
  DeliveryItem();

  void set_DeliveryItemPrice(int price) {
    this->deliveryPrice = price;
  }

  int get_saleItemPrice() {
    return this->deliveryPrice;
  }

  void Show() {
    consignmentItem::Show();
    cout << "Delivery price: " << this->get_saleItemPrice() << endl;
    ADelivery.Show();
  }
  friend ostream& operator<<(ostream& os, const DeliveryItem& DeliveryItem_n);
};

ostream& operator<<(ostream& os, const DeliveryItem& DeliveryItem_n)
{
  //os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count     DelYear    DelWeek    DelPrice" << endl;
  os << (consignmentItem&)DeliveryItem_n;
  os << "     ";
  os << (Date&)DeliveryItem_n.ADelivery;
  os.width(13);
  os << DeliveryItem_n.deliveryPrice;
  return os;
}

DeliveryItem::DeliveryItem() {
  this->set_DeliveryItemPrice(rand() % 9999 + 1);
}

class saleItem : virtual public consignmentItem {
protected:
  Date ASale;
  int salePrice;
public:
  saleItem();

  void set_saleItemPrice(int price) {
    this->salePrice = price;
  }

  int get_salePrice() {
    return this->salePrice;
  }

  Date get_ASale() {
    return this->ASale;
  }

  void Show() {
    consignmentItem::Show();
    cout << "Sale item price: " << this->get_salePrice() << endl;
    ASale.Show();
  }
  friend ostream& operator<<(ostream& os, const saleItem& saleItem_n);
};

ostream& operator<<(ostream& os, const saleItem&saleItem_n)
{
  //os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count     SaleYear   SaleWeek    SalePrice" << endl;
  os << (consignmentItem&)saleItem_n;
  os << "     ";
  os << (Date&)saleItem_n.ASale;
  os.width(15);
  os << saleItem_n.salePrice;
  return os;
}

saleItem::saleItem() {
  this->set_saleItemPrice(rand() % 9999 + 1);
}

void init_consignmentItem(consignmentItem *consignmentItem_n);
void init_FlowerItem(FlowerItem *FlowerItem_n);
void init_DeliveryItem(DeliveryItem *DeliveryItem_n);
void init_saleItem(saleItem *saleItem_n);

class DayBalance : virtual public DeliveryItem, virtual public saleItem {
protected:
  saleItem *DayBalanceList;
  int count;
public:
  DayBalance();

  void set_dayBalanceCount(int count_n) {
    this->count = count_n;
  }

  int get_dayBalanceCount() {
    return this->count;
  }

  saleItem* get_DayBalanceList() {
    return this->DayBalanceList;
  }

  /*------------------------------------*/
  saleItem& operator [] (int i) {

    if (i < 0 || i >= get_dayBalanceCount()) {
      cout << "INDEX ERROR!";
      exit(1);
    }
    return DayBalanceList[i];
  }
  /*-------------------------------------*/

  void Show() {
    cout << endl << "|-----Delivery : " << endl;
    DeliveryItem::Show();
    cout << endl << "-----|" << endl;
    for (int i = 0; i < this->get_dayBalanceCount(); i++) {
      cout << endl << "|_______Sale item list : " << endl;
      DayBalanceList[i].Show();
      cout << endl << "________|" << endl;
    }
  }

  void WriteFile();
  void WriteFileBinary();

  friend ostream& operator<<(ostream& os, const  DayBalance& DayBalance_n);
};
/*------------------------------------------------------------------------------------------------------------------------------*/
ostream& operator<<(ostream& os, const DayBalance& DayBalance_n)
{
  os << "Delivered item: " << endl;
  //os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count    DelYear    DelWeek    DelPrice  ListCount   SaleYear    SaleWeek    SalePrice      DayBalanceList[i]" << endl;
  os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count    DelYear    DelWeek    DelPrice" << endl;
  os << (DeliveryItem&)DayBalance_n;
  os << "     ";
  os << endl << endl;
  os << "Sale items: " << endl;
  os << "ListCount   SaleYear   SaleWeek    SalePrice    flowerName     flowerColor   TypeSaleType    Flower Price      Count " << endl;
  os.width(5);
  os << DayBalance_n.count;
  for (int i = 0; i < DayBalance_n.count; i++) {
    //os << "flowerName     flowerColor   TypeSaleType    Flower Price     Count     SaleYear   SaleWeek    SalePrice" << endl;
    //os << (DeliveryItem&)DayBalance_n;
    //os << "     ";
    //os << DayBalance_n.DayBalanceList[i].ASale endl;
    os << "       ";
    os.width(16);
    os << (Date&)DayBalance_n.DayBalanceList[i].get_ASale();
    os.width(14);
    //os << "  ";
    os << DayBalance_n.DayBalanceList[i].get_salePrice();
    os << "        ";
    //os << "     ";
    os << (consignmentItem&)DayBalance_n; // or (consignmentItem&)DayBalance_n.DayBalanceList[i]
    //os << (saleItem&)DayBalance_n;
    os.width(12);
    os << endl;
  }
  return os;
}

void init_DayBalance(DayBalance *DayBalance_n);

DayBalance::DayBalance() {
  this->set_dayBalanceCount(rand() % 256 + 1);
  /*cout << endl << "|-----Delivery : " << endl;
  DeliveryItem::Show();
  cout << endl << "-----|" << endl;*/
  DayBalanceList = new saleItem[this->get_dayBalanceCount()];
  for (int i = 0; i < this->get_dayBalanceCount(); i++) {
    init_saleItem(&DayBalanceList[i]);
    /*cout << endl << "|_______Sale item list : " << endl;
    DayBalanceList[i].Show();
    cout << endl << "________|" << endl;*/
  }
}

void DayBalance::WriteFile() {
  ofstream file_out("file_single_out.txt");
  file_out << *this;
  file_out.close();
}

void DayBalance::WriteFileBinary() {
  ofstream file_out("file_binary_out.txt", ios_base::binary);
  file_out << *this;
  file_out.close();
}

void init_FlowerItem(FlowerItem *FlowerItem_n) {

  FlowerItem Obj;
  *FlowerItem_n = Obj;
}

void init_consignmentItem(consignmentItem *consignmentItem_n) {

  consignmentItem Obj;
  init_FlowerItem(consignmentItem_n);
  *consignmentItem_n = Obj;
}

void init_DeliveryItem(DeliveryItem *DeliveryItem_n) {

  DeliveryItem Obj;
  init_consignmentItem(DeliveryItem_n);
  *DeliveryItem_n = Obj;
}

void init_saleItem(saleItem *saleItem_n) {

  saleItem Obj;
  init_consignmentItem(saleItem_n);
  *saleItem_n = Obj;
}

void init_DayBalance(DayBalance *DayBalance_n) {
  init_DeliveryItem(DayBalance_n);
}

template <class AnyType>
double average(AnyType a) {
  double sum = 0;
  cout << a.get_dayBalanceCount();
  cout << endl << endl << endl;
  for (int i = 0; i < a.get_dayBalanceCount(); i++) {
    cout << a[i].get_salePrice() << endl;
    sum += a[i].get_salePrice();
  }
  return sum / a.get_dayBalanceCount();
}



template <class AnyType>
class DayBalance_NEW : virtual public DeliveryItem, virtual public saleItem {
protected:
  AnyType *List;
  int count;
public:
  DayBalance_NEW();
  void set_dayBalanceCount(int count_n) {
    this->count = count_n;
  }

  int get_dayBalanceCount() {
    return this->count;
  }

  void Show() {
    cout << endl << "|-----Delivery : " << endl;
    DeliveryItem::Show();
    cout << endl << "-----|" << endl;
    for (int i = 0; i < this->get_dayBalanceCount(); i++) {
      cout << endl << "|_______Sale item list : " << endl;
      List[i].Show();
      cout << endl << "________|" << endl;
    }
  }
};

template<class AnyType>
DayBalance_NEW<AnyType>::DayBalance_NEW() {
  this->set_dayBalanceCount(rand() % 256 + 1);

  List = new AnyType[this->get_dayBalanceCount()];
  for (int i = 0; i < this->get_dayBalanceCount(); i++) {
    init_saleItem(&List[i]);
  }
}
/*additional template*/
template <class AnyType>
class DATE_NEW {
protected:
  AnyType dateYear;
  AnyType dateWeek;
public:
  DATE_NEW();

  void set_dateYear(AnyType year) {
    this->dateYear = year;
  }

  void set_dateWeek(AnyType week) {
    this->dateWeek = week;
  }

  AnyType get_dateYear() {
    return this->dateYear;
  }

  AnyType get_dateWeek() {
    return this->dateWeek;
  }

  virtual void Show() {
    cout << "Date year: " << setprecision(4) << this->get_dateYear()
      << ". Date week: " << setprecision(4) << this->get_dateWeek() << endl;
  }
};

template<class AnyType>
DATE_NEW<AnyType>::DATE_NEW() {
  this->set_dateYear(rand() % 100 / 1.5);
  this->set_dateWeek(rand() % 100 / 1.5);
}



int main() {
  srand(time(NULL));
  clock_t t;
  t = clock();
  /*
  int i = 0;
  DayBalance anton;
  init_DayBalance(&anton);
  anton.Show();
  double a;
  a = average(anton);
  cout << "AVERAGE : " << a << endl;
  */

  DayBalance a;
  cout << a;
  a.WriteFile();
  a.WriteFileBinary();

  /*DATE_NEW<double> a;
  a.Show();*/

  /*DayBalance_NEW<saleItem> a;
  a.Show();*/
  


  t = clock() - t;
  printf("\n\n\nIt took me %d clicks (%f seconds).\n", (int)t, ((double)t) / CLOCKS_PER_SEC);
  system("pause");
  return 0;
}