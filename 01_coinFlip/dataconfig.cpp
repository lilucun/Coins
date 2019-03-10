#include "dataconfig.h"



// 初始化数据
void dataConfig::randData()
{
    srand(time(NULL));
    for(int i=0;i<20;i++)
    {
        int array1[6][6] = {0} ;
        for(int j=0;j<6;j++)
        {
            for(int z=0;z<6;z++)
            {
                array1[j][z]  = rand()%2;
            }
        }

        QVector< QVector<int>> v;
        for(int i = 0 ; i < 6;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 6;j++)
            {

                v1.push_back(array1[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(i+1,v);
    }

}


dataConfig::dataConfig(int easyLevel, QObject *parent) : QObject(parent)
{
    // level 4
    if(easyLevel == 4)
    {
        int array1[4][4] = {{1, 1, 1, 1},
                            {1, 1, 0, 1},
                            {1, 0, 0, 0},
                            {1, 1, 0, 1} } ;

        QVector< QVector<int>> v;
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {

                v1.push_back(array1[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(1,v);


        int array2[4][4] = { {1, 0, 1, 1},
                             {0, 0, 1, 1},
                             {1, 1, 0, 0},
                             {1, 1, 0, 1}} ;

        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array2[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(2,v);



        int array3[4][4] = {  {0, 0, 0, 0},
                              {0, 1, 1, 0},
                              {0, 1, 1, 0},
                              {0, 0, 0, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array3[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(3,v);


        int array4[4][4] = {   {0, 1, 1, 1},
                               {1, 0, 0, 1},
                               {1, 0, 1, 1},
                               {1, 1, 1, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array4[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(4,v);


        int array5[4][4] = {  {1, 0, 0, 1},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {1, 0, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array5[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(5,v);


        int array6[4][4] = {   {1, 0, 0, 1},
                               {0, 1, 1, 0},
                               {0, 1, 1, 0},
                               {1, 0, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array6[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(6,v);


        int array7[4][4] = {   {0, 1, 1, 1},
                               {1, 0, 1, 1},
                               {1, 1, 0, 1},
                               {1, 1, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array7[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(7,v);

        int array8[4][4] = {  {0, 1, 0, 1},
                              {1, 0, 0, 0},
                              {0, 0, 0, 1},
                              {1, 0, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array8[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(8,v);

        int array9[4][4] = {   {1, 0, 1, 0},
                               {1, 0, 1, 0},
                               {0, 0, 1, 0},
                               {1, 0, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array9[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(9,v);



        int array10[4][4] = {  {1, 0, 1, 1},
                               {1, 1, 0, 0},
                               {0, 0, 1, 1},
                               {1, 1, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array10[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(10,v);


        int array11[4][4] = {  {0, 1, 1, 0},
                               {1, 0, 0, 1},
                               {1, 0, 0, 1},
                               {0, 1, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array11[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(11,v);

        int array12[4][4] = {  {0, 1, 1, 0},
                               {0, 0, 0, 0},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array12[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(12,v);


        int array13[4][4] = {    {0, 1, 1, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 1, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array13[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(13,v);

        int array14[4][4] = {    {1, 0, 1, 1},
                                 {0, 1, 0, 1},
                                 {1, 0, 1, 0},
                                 {1, 1, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array14[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(14,v);


        int array15[4][4] = {   {0, 1, 0, 1},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {0, 1, 0, 1}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array15[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(15,v);


        int array16[4][4] = {   {0, 1, 1, 0},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {0, 1, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array16[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(16,v);

        int array17[4][4] = {  {0, 1, 1, 1},
                               {0, 1, 0, 0},
                               {0, 0, 1, 0},
                               {1, 1, 1, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array17[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(17,v);


        int array18[4][4] = { {0, 0, 0, 1},
                              {0, 0, 1, 0},
                              {0, 1, 0, 0},
                              {1, 0, 0, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array18[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(18,v);

        int array19[4][4] = {   {0, 1, 0, 0},
                                {0, 1, 1, 0},
                                {0, 0, 1, 1},
                                {0, 0, 0, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array19[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(19,v);

        int array20[4][4] = {  {0, 0, 0, 0},
                               {0, 0, 0, 0},
                               {0, 0, 0, 0},
                               {0, 0, 0, 0}} ;
        v.clear();
        for(int i = 0 ; i < 4;i++)
        {
            QVector<int>v1;
            for(int j = 0 ; j < 4;j++)
            {
                v1.push_back(array20[i][j]);
            }
            v.push_back(v1);
        }

        mData.insert(20,v);
    }

    // level 6
    else if(easyLevel == 6)
    {
        randData();
    }

}