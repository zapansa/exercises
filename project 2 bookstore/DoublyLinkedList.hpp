#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add helper methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom and DLL !
 */
namespace CPSC131::DoublyLinkedList
{
	/**
	 * Implement our DoublyLinkedList class !
	 */
	template <class T>
	class DoublyLinkedList
	{
		public:

			/**
			 * Node class, representing a single item in our linked list
			 */
			// TODO: Complete all class methods
			class Node
			{
				public:
					
					/// CTORS
					/// Member initialization lists?
					Node() : prev_(nullptr), next_(nullptr) {}
					Node(T element) : element_(element), prev_(nullptr), next_(nullptr) {}
					Node(T element, Node *prev, Node *next) : element_(element), prev_(prev), next_(next) {}

					/// Set the pointer to the previous element
					void setPrevious(Node *prev) { prev_ = prev; }

					/// Set the pointer to the previous element
					void setPrev(Node *prev) { prev_ = prev; }

					/// Get a pointer to the previous element
					Node *getPrevious() { return prev_; }

					/// Get a pointer to the previous element
					Node *getPrev() { return prev_; }

					/// Set the pointer to the next node
					void setNext(Node *next) { next_ = next; }

					/// Get a pointer to the next node
					Node *getNext() { return next_; }

					/// Set the element this node holds
					void setElement(T element) { element_ = element; }

					/// Get the element this node holds
					T &getElement() { return element_; }

					/// Return a reference to the element
					T& operator*() { return this->element_; }
					
				private:
					T element_;
					Node* prev_;
					Node* next_;
			};
			
			/**
			 * Nested Iterator class.
			 * This allows user code to refer to the Iterator's type as:
			 * 
			 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
			 * 
			 * (as opposed to specifying the template argument two times)
			 */
			class Iterator
			{
				public:
					
					///	Constructor that does nothing; YOUR WELCOME
					Iterator() : head_(nullptr), tail_(nullptr), cursor_(nullptr) {}

					///	Constructor taking a head and tail pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
					{
						this->cursor_ = this->end();
					}
					
					///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
					
					///	Get a pointer to the head node, or end() if this list is empty
					Node* begin() { return head_; }

					///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
					Node *end() { return nullptr; }

					///	Get the node to which this iterator is currently pointing
					Node *getCursor() { return cursor_; }

					///	Return true if this iterator has hit its end; false otherwise
					bool isAtEnd()
					{
						return this->cursor_ == nullptr;
					}
					
					/**
					 * Assignment operator
					 * Return a copy of this Iterator, after modification
					 */
					Iterator& operator=(const Iterator& other)
					{
						head_ = other.head_;
						tail_ = other.tail_;
						cursor_ = other.cursor_;
						return *this;
					}
					
					///	Comparison operator
					bool operator==(const Iterator& other)
					{
						return cursor_ == other.cursor_;
					}

					///	Inequality comparison operator
					bool operator!=(const Iterator& other) const
					{
						return cursor_ != other.cursor_;
					}
					
					/**
					 * Addition operator
					 */
					Iterator operator +(size_t add)
					{
						Iterator temp = *this;
						for (size_t i = 0; i < add && temp.cursor_ != nullptr; ++i)
						{
							temp.cursor_ = temp.cursor_->getNext();
						}
						return temp;
					}
					
					/**
					 * Subtraction operator
					 */
					Iterator operator -(size_t subtract)
					{
						Iterator temp = *this;
						for (size_t i = 0; i < subtract && temp.cursor_ != nullptr; ++i)
						{
							temp.cursor_ = temp.cursor_->getPrevious();
						}
						return temp;
					}
					
					/**
					 * Prefix increment operator
					 * Return a copy of this Iterator, after modification
					 */
					Iterator& operator++()
					{
						if (cursor_ != nullptr)
							cursor_ = cursor_->getNext();
						return *this;
					}
					
					/**
					 * Postfix increment
					 * Return a copy of this Iterator, BEFORE it was modified
					 */
					Iterator operator++(int)
					{
						Iterator temp = *this;
						if (cursor_ != nullptr)
							cursor_ = cursor_->getNext();
						return temp;
					}
					
					/**
					 * Prefix decrement operator
					 * Return a copy of this Iterator, after modification
					 */
					Iterator& operator--()
					{
						if (cursor_ != nullptr)
						{
							cursor_ = cursor_->getPrevious();
						}
						return *this;
					}
					
					/**
					 * Postfix decrement operator
					 * Return a copy of this Iterator BEFORE it was modified
					 */
					Iterator operator--(int)
					{
						Iterator temp = *this;
						if (cursor_ != nullptr)
						{
							cursor_ = cursor_->getPrevious();
						}
						return temp;
					}
					
					/**
					 * AdditionAssignment operator
					 * Return a copy of the current iterator, after modification
					*/
					Iterator operator +=(size_t add)
					{
						for (size_t i = 0; i < add && cursor_ != nullptr; ++i)
						{
							cursor_ = cursor_->getNext();
						}
						return *this;
					}
					/**
					 * SubtractionAssignment operator
					 * Return a copy of the current iterator, after modification
					 */
					Iterator operator -=(size_t add)
					{
						for (size_t i = 0; i < add && cursor_ != nullptr; ++i)
						{
							cursor_ = cursor_->getPrevious();
						}
						return *this;
					}
					
					/**
					 * AdditionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator +=(int add)
					{
						if (add > 0)
						{
							return *this += static_cast<size_t>(add);
						}
						else
						{
							return *this -= static_cast<size_t>(-add);
						}
					}
					
					/**
					 * SubtractionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator -=(int subtract)
					{
						if (subtract > 0)
						{
							return *this -= static_cast<size_t>(subtract);
						}
						else
						{
							return *this += static_cast<size_t>(-subtract);
						}
					}
					
					/**
					 * Dereference operator returns a reference to the ELEMENT contained with the current node
					 */
					T& operator*()
					{
						if (cursor_ == nullptr)
						{
							throw std::out_of_range("Iterator is out of range");
						}
						return cursor_->getElement();
					}
				
				private:
					
					/// Pointer to the head node
					Node* head_;
					
					/// Pointer to the tail node
					Node* tail_;
					
					/// Pointer to the cursor node.
					Node* cursor_;
				
				friend class DoublyLinkedList;
			};
			
			/// Default constructor
			DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

			///	Copy Constructor
			DoublyLinkedList(DoublyLinkedList &other) : head_(nullptr), tail_(nullptr), size_(0)
			{
				assign(other.begin(), other.last());
			}

			/// DTOR
			~DoublyLinkedList() { clear(); }

			/**
			 * Clear the list and assign the same value, count times.
			 * 
			 * Example:
			 *   T is an int
			 *   count is 5
			 *   value = 3
			 * 
			 * Our list would become:
			 *   {3, 3, 3, 3, 3}
			 */
			void assign(size_t count, const T& value)
			{
				clear();
				for (size_t i = 0; i < count; ++i)
				{
					push_back(value);
				}
			}
			
			/**
			 * Clear the list and assign values from another list.
			 * The 'first' iterator points to the first item copied from the other list.
			 * The 'last' iterator points to the last item copied from the other list.
			 * 
			 * Example:
			 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
			 * 	Suppose first points to the 4 node
			 *	Suppose last points to the 7 node
			 * 	We should end up with our list becoming: {4, 3, 2, 7}
			 *
			 * If the user code sends out-of-order iterators,
			 * 	just copy from 'first' to the end of the source list
			 * 
			 * Example:
			 *  If we have the same source list {8, 4, 3, 2, 7, 1},
			 *  and first points to the 7 node,
			 *  and last points to the 4 node,
			 *  we would end up with: {7, 1}
			 */
			void assign(Iterator first, Iterator last)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			}
			
			/// Return a pointer to the head node, if any
			Node *head() const { return head_; }

			/// Return a pointer to the tail node, if any
			Node *tail() const { return tail_; }

			/**
			 * Return an iterator that points to the head of our list
			 */
			Iterator begin() const { return Iterator(head_, tail_); }

			/**
			 * Return an iterator that points to the last element (tail) of our list
			 */
			Iterator last() const { return Iterator(head_, tail_, tail_); }

			/**
			 * Should return an iterator that represents being past the end of our nodes,
			 * or just that we are finished.
			 * 
			 * You can make this a nullptr or use some other scheme of your choosing,
			 * 	as long as it works with the logic of the rest of your implementations.
			 */
			Iterator end() const { return Iterator(head_, tail_, nullptr); }

			/**
			 * Returns true if our list is empty
			 */
			bool empty() const { return size_ == 0; }

			/**
			 * Returns the current size of the list
			 * 
			 * Should finish in constant time!
			 * (keep track of the size elsewhere)
			 */
			size_t size() const { return size_; }

			/**
			 * Clears our entire list, making it empty
			 */
			void clear()
			{
				while (!empty())
				{
					pop_front();
				}
			}

			/**
			 * Insert an element after the node pointed to by the pos Iterator
			 * 
			 * If the list is currently empty,
			 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
			 * 
			 * If the incoming iterator is this->end(),
			 *   insert the element as the new tail
			 * 
			 * Should return an iterator that points to the newly added node
			 */
			Iterator insert_after(Iterator pos, const T& value)
			{

				// Find position to insert new node
				Iterator it = begin();
				while (it != end() && it != pos)
				{
					++it;
				}

				// if it reaches the end or doesnt match 
				// insert at the end of the list 
				if (it == end())
				{
					push_back(value);
					return --end(); // return an iterator pointing to the last node
				}
				else
				{
					Node *current = it.getCursor();
					Node *newNode = new Node(value, current, current->getNext());
					current->setNext(newNode);
					if (newNode->getNext())
					{
						newNode->getNext()->setPrevious(newNode);
					}
					else
					{
						tail_ = newNode;
					}
					++size_;
					return Iterator(head_, tail_, newNode);
				}
			}

			/**
			 * Insert a new element after the index pos.
			 * Should work with an empty list.
			 * 
			 * Should return an iterator pointing to the newly created node
			*/
			Iterator insert_after(size_t pos, const T& value)
			{
				Iterator it = begin();
				for (size_t i = 0; i < pos && it != end(); ++i, ++it)
					;
				return insert_after(it, value);
			}

			/**
			 * Erase the node pointed to by the Iterator's cursor.
			 * 
			 * If the 'pos' iterator does not point to a valid node,
			 * 	throw an std::range_error
			 * 
			 * Return an iterator to the node AFTER the one we erased,
			 * 	or this->end() if we just erased the tail
			 */
			Iterator erase(Iterator pos)
			{
				if (empty())
					throw std::range_error("Cannot erase from an empty list.");

				Node *current = pos.getCursor();
				if (!current)
					throw std::range_error("Iterator does not point to a valid node.");

				Node *nextNode = current->getNext();
				Node *prevNode = current->getPrevious();

				if (prevNode)
					prevNode->setNext(nextNode);
				else
					head_ = nextNode;

				if (nextNode)
					nextNode->setPrevious(prevNode);
				else
					tail_ = prevNode;

				delete current;
				--size_;

				if (nextNode)
					return Iterator(head_, tail_, nextNode);
				else
					return end();
			}
			
			/**
			 * Add an element just after the one pointed to by the 'pos' iterator
			 * 
			 * Should return an iterator pointing to the newly created node
			 */
			Iterator push_after(Iterator pos, const T& value)
			{
				if (empty())
				{
					return push_front(value);
				}
				if (pos == end())
				{
					return push_back(value);
				}

				Node *current = pos.getCursor();

				Node *newNode = new Node(value); // New node with given value

				// update pointers
				newNode->setNext(current->getNext());
				newNode->setPrevious(current);

				if (current->getNext()) // check if theres a next node
				{
					current->getNext()->setPrevious(newNode);
				}
				else // if the current is the tail
				{
					tail_ = newNode;
				}

				current->setNext(newNode);
				
				++size_;

				return Iterator(head_, tail_, newNode);
			}
			
			/**
			 * Add a new element to the front of our list.
			 */
			void push_front(const T& value)
			{
				Node *newNode = new Node(value);
				if (empty())
				{
					head_ = newNode;
					tail_ = newNode;
				}
				else
				{
					newNode->setNext(head_);
					head_->setPrevious(newNode);
					head_ = newNode;
				}
				++size_;
			}
			
			/**
			 * Add an element to the end of this list.
			 * 
			 * Should return an iterator pointing to the newly created node.
			 */
			Iterator push_back(const T& value)
			{
				Node *newNode = new Node(value);
				if (empty())
				{
					head_ = newNode;
					tail_ = newNode;
				}
				else
				{
					tail_->setNext(newNode);
					newNode->setPrevious(tail_);
					tail_ = newNode;
				}
				++size_;
				return Iterator(head_, tail_, newNode);
			}
			
			/**
			 * Remove the node at the front of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_front()
			{
				if (empty())
					throw std::range_error("Cannot pop from an empty list.");

				Node *temp = head_;
				head_ = head_->getNext();
				delete temp;

				if (head_)
					head_->setPrevious(nullptr);
				else
					tail_ = nullptr;

				--size_;
			}
			
			/**
			 * Remove the node at the end of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_back()
			{
				if (empty())
					throw std::range_error("Cannot pop from an empty list.");

				Node *temp = tail_;
				tail_ = tail_->getPrevious();
				delete temp;

				if (tail_)
					tail_->setNext(nullptr);
				else
					head_ = nullptr;

				--size_;
			}
			
			/**
			 * Return a reference to the element at the front.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& front()
			{
				if (empty())
					throw std::range_error("Cannot access front element of an empty list.");
				return head_->getElement();
			}
			
			/**
			 * Return a reference to the element at the back.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& back()
			{
				if (empty())
					throw std::range_error("Cannot access back element of an empty list.");
				return tail_->getElement();
			}
			
			/**
			 * Return the element at an index
			 * 
			 * Should throw a range_error is out of bounds
			 */
			T& at(size_t index)
			{
				if (index >= size_)
					throw std::range_error("Index out of bounds.");

				if(index < size_ / 2){
					Node *current = head_;
					for (size_t i = 0; i < index; ++i)
						current = current->getNext();
					return current->getElement();
				}
				else // search tail 
				{
					Node* current = tail_;
					for (size_t i = size_ - 1; i > index; --i)
						current = current->getPrevious();
					return current->getElement();
				}
			}
			
			/**
			 * Reverse the current list
			 */
			void reverse()
			{
				if (empty() || size_ == 1)
					return;

				Node *current = head_;
				Node *temp = nullptr;

				while (current != nullptr)
				{
					temp = current->getPrevious();
					current->setPrevious(current->getNext());
					current->setNext(temp);
					current = current->getPrevious();
				}

				temp = head_;
				head_ = tail_;
				tail_ = temp;
			}
			
			/**
			 * I bet you're happy I'm not making you do this.
			 * No tests will be run against this function,
			 * 	but feel free to try it out, as a challenge!
			 * 
			 * If I were doing this and didn't care too much for efficiency,
			 * 	I would probably create an extra helper function to swap two
			 * 	positions in the current list.
			 * Then I would simply sweep through the list and perform
			 *  the bubble-sort algorithm. Perhaps selection sort.
			 * 
			 * If you want a huge challenge, try implementing quicksort.
			 * 
			 * (but again, don't worry about this method; it will not be tested)
			 */
			void sort()
			{
				//	TODO: Your code here


				// ****** sorry christian but absolutely not. ********
				// i am NOT implementing a sort on a doubly linked list no thanks 


			}
			
			/**
			 * Assignment operator
			 * 
			 * Clear this list and fill it with the others' values
			 * (by value, not by reference)
			 * 
			 * Return a reference to this list
			 */
			DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
			{
				if (this == &other)
					return *this;

				clear();
				assign(other.begin(), other.end());
				return *this;
			}
			
			/**
			 * Return true if the lists are "equal"
			 * 
			 * "Equal" here is defined as:
			 * - Same size
			 * - Elements at the same indexes would return true for their own comparison operators
			 * 
			 * In other words: "They contain all the same values"
			 * (no need for their pointers or addresses to be the same)
			 */
			bool operator ==(DoublyLinkedList<T>& other)
			{
				if (size_ != other.size())
					return false;

				Iterator it1 = begin();
				Iterator it2 = other.begin();

				while (it1 != end())
				{
					if (*it1 != *it2)
						return false;
					++it1;
					++it2;
				}

				return true;
			}
			
			/**
			 * Return true if the lists are "not equal"
			 * 
			 * See the operator== stub for definition of "equal"
			 */
			bool operator !=(DoublyLinkedList<T>& other)
			{
				return !(*this == other);
			}
			
		private:
			
			Node* head_ = nullptr;
			Node* tail_ = nullptr;
			size_t size_ = 0;
	};
}

#endif
