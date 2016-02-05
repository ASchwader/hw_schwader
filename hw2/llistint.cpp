#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if(loc < 0 || loc > size_)
    {
        return;
    }

    Item *temp, *move; //*curr;
    temp = new Item;
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;
    if(loc == 0)
    {
        if(size_ == 0)
        {
            head_ = temp;

        }
        else
        {
            temp->next = head_;
            temp->prev = NULL;
            head_->prev = temp;
            head_ = temp;
        }
    }
    else if (loc == size_)
    {
        move = head_;
        for(int i = 0; i < loc-1; i++)
        {
            move = move->next;
        }
        move->next = temp;
        temp->next = NULL;
        temp->prev = move;
    }
    else
    {
        move = getNodeAt(loc);
        temp->next = move;
        temp->prev = move->prev;
        move->prev->next = temp;
        move->prev = temp;

    }

    size_++;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
   if(loc < 0 || loc > (size_ -1) || size_ == 0)
    {
        return;
    }

    else
    {
        Item *rem;
        rem = head_;

        if(loc == 0)
        {
            rem = head_;
            head_ = head_->next;
            delete rem;
        }


        else
        {
              rem = getNodeAt(loc);
              /*for(int i = 0; i < loc; i++)
              {
                   rem = rem->next;

              } */
              if(loc == (size_-1))
              {
                  rem->prev->next = NULL;
                  delete rem;
              }
              else
              {
                  rem->prev->next = rem->next;
                  rem->next->prev = rem->prev;
                  delete rem;
              }
        }
    }
    size_--;
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
   if(loc < 0 || loc > (size_ -1) || size_ == 0)
    {
        return NULL;
    }

    else
    {
        Item *ret;
        ret = head_;
        for(int i = 0; i < loc; i++)
        {
            ret = ret->next;
        }
        return ret;
    }
    
}
