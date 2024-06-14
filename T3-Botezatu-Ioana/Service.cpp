//
// Created by user on 25.05.2023.
//

#include "Service.h"

void sort()
{
    auto doc=this->repo->getAll();
    for(int i=0;i<std::size(doc),i++)
        for(int j=i+1;j<=std::size(doc),j++)
            if(doc[i].name>doc[j].name)
                swap(doc[i],doc[j]);

}