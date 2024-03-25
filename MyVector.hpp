
/**
 * TODO: Complete this class!
 */


/// Your welcome
#include <assert.h>
#include <iostream>
#include <string>

namespace CPSC131::MyVector
{

	//
	template <typename T>
	class MyVector
	{
		public:
			
			/*******************
			 * Static constants
			 ******************/
			
			/// Default capacity
			static constexpr size_t DEFAULT_CAPACITY = 64;
			
			/// Minimum capacity
			static constexpr size_t MINIMUM_CAPACITY = 8;
			
			/*****************************
			 * Constructors / Destructors
			 ****************************/
			
			/// Normal constructor
			MyVector(size_t capacity = MyVector::DEFAULT_CAPACITY)
			{
				size_ = 0; 
				capacity_ = (capacity < MINIMUM_CAPACITY) ? MINIMUM_CAPACITY : capacity; // Fix
				elements_ = new T[capacity_];
			}
			
			/// Copy constructor
			MyVector(const MyVector& other)
			{
				// Without the colon initializer list
				size_ = other.size_; 
				capacity_ = other.capacity_;
				elements_ = new T[other.capacity_];
				
				for(size_t i = 0; i < size_; ++i) 
				{
					elements_[i] = other.elements_[i];
				}
			}
			
			/**
			 * Destructor
			 * Cleanup here.
			 */
			~MyVector()
			{
				clear();
				delete[] elements_;
			}
			
			/************
			 * Operators
			 ************/
			
			///	Assignment operator TODO ******
			MyVector& operator=(const MyVector& rhs)
			{
				if(this != &rhs)
				{
					clear();
					copyOther(rhs);
				}
				return *this;
			}
			
			/// Operator overload to at() TODO ****
			T& operator[](size_t index) const
			{
				return at(index);
			}
			
			/************
			 * Accessors
			 ************/
			
			/// Return the number of valid elements in our data
			size_t size() const
			{
				return size_;
			}
			
			/// Return the capacity of our internal array
			size_t capacity() const
			{
				return capacity_;
			}
			
			/**
			 * Check whether our vector is empty
			 * Return true if we have zero elements in our array (regardless of capacity)
			 * Otherwise, return false
			 */
			bool empty() const
			{
				if (size_ == 0) 
				{
					return true;
				}
				else
				return false;
			}
			
			/// Return a reference to the element at an index
			T& at(size_t index) const
			{
				if (index >= size_)
				{
					throw std::out_of_range("The index is out of range");
				}
				return elements_[index];
			}		

			/***********
			 * Mutators
			 ***********/
			
			/**
			 * Reserve capacity in advance, if our capacity isn't currently large enough.
			 * Useful if we know we're about to add a large number of elements,
			 *   and we'd like to avoid the overhead of many internal changes to capacity.
			 */
			void reserve(size_t capacity)
			{
				if (capacity > capacity_)
				{
					changeCapacity(capacity);
				}
			}
			
			/**
			 * Set an element at an index.
			 * Throws range error if outside the size boundary.
			 * Returns a reference to the newly set element (not the original)
			 */
			T& set(size_t index, const T& element)
			{
				if (index >= size_)
				{
					throw std::out_of_range("Index is out of range");
				}
				elements_[index] = element;
				return elements_[index]; // flag 
			}
			
			/**
			 * Add an element onto the end of our vector.
			 * Returns a reference to the newly inserted element.
			 */
			T& push_back(const T& element)
			{
				// reserve bc same 
				if(size_ == capacity_)
				{
					reserve(capacity_ * 2);
					// if (size_ < (capacity_ / 3))
					// {
					// 	changeCapacity(capacity_ / 2);
					// }
				}
				elements_[size_++] = element;
				return elements_[size_-1];
			}
			
			/**
			 * Remove the last element in our vector.
			 * Should throw std::range_error if the vector is already empty.
			 * Returns a copy of the element removed.
			 */
			T pop_back()
			{
				if(size_ == 0)
				{
					throw std::range_error("The vector is empty");
				} 
				else if (size_ == 1)
				{
					T poppedElement = elements_[--size_];
					changeCapacity(MINIMUM_CAPACITY);
					return poppedElement;
				}
				if (size_ < (capacity_/3))
				{
					changeCapacity(capacity_/2);
				}
				return elements_[--size_];
			}		
			
			
			/**
			 * Insert an element at some index in our vector
			 * 
			 * Example:
			 * 	 Insert a 9 at index 2
			 *   Contents before: [6, 2, 7, 4, 3]
			 *   Contents after:  [6, 2, 9, 7, 4, 3]
			 * 
			 * Returns a reference to the newly added element (not the original).
			 */
			T& insert(size_t index, const T& element)
			{
				if(index > size_)
				{
					throw std::out_of_range("The index is out of range.");
				}
				if(size_ == capacity_)
				{
					reserve(capacity_ * 2);
					// if(size_ < (capacity_ / 3))
					// {
					// 	changeCapacity(capacity_/2);
					// }
				}
				for(size_t i = size_; i > index; --i)
				{
					elements_[i] = elements_[i - 1];
				}
				elements_[index] = element;
				++size_; 
				return elements_[index];

			}
			
			/**
			 * Erase one element in our vector at the specified index
			 * 
			 * Throws std::range_error if the index is out of bounds.
			 * 
			 * Example:
			 *   Erase index 2
			 *   Contents before: [8, 4, 3, 9, 1]
			 *   Contents after:  [8, 4, 9, 1]
			 * 
			 * Returns a copy of the erased element.
			 * Hint: call DTOR on original after making the copy.
			 */
			T erase(size_t index)
			{
				if(index >= size_)
				{
					throw std::out_of_range("Index is out of range.");
				}
				T erasedElement = elements_[index];
				for (size_t i = index; i < size_ - 1; ++i)
				{
					elements_[i] = elements_[i + 1];
				}
				--size_;
				return erasedElement;
			}
			
			/**
			 * Removes all elements (i.e., size=0 and DTORs called)
			 * 
			 * Should also reset capacity, if needed
			*/
			void clear()
			{
				size_ = 0; 
				capacity_ = 0; 
			}
		
		/**
		 * Begin private members and methods.
		 * You may add your own private helpers here, if you wish.
		*/
		private:
			/// Number of valid elements currently in our vector
			size_t size_ = 0;
			
			/// Capacity of our vector; The actual size of our internal array
			size_t capacity_ = 0;
			
			/**
			 * Our internal array of elements of type T.
			 * Starts off as a null pointer.
			 */
			T* elements_ = nullptr;
			
			/**
			 * Helper function that is called whenever we need to change the capacity of our vector.
			 * Should throw std::range_error when asked to change to a capacity that cannot hold our existing elements.
			 */
			void changeCapacity(size_t c)
			{
				if(c < size_)
				{
					throw std::out_of_range("The new capacity entered is less than the old.");
				}
				if(c < MINIMUM_CAPACITY)
				{
					c = MINIMUM_CAPACITY;
				}
				T* temp = new T[c];
				for(size_t i = 0; i < size_; ++i)
				{
					temp[i] = elements_[i];
				}
				delete[] elements_;
				elements_ = temp;
				capacity_ = c;
			}

			/** Helper function 
			 *  Private member function of the class. Its purpose is to copy the contents of another MyVector object into the
			 *  current object. Used in the copy constructor and the assignment operator. 
			 */
			void copyOther(const MyVector& other)
			{
				size_ = other.size_; 
				capacity_ = other.capacity_;
				elements_ = new T[capacity_];
				for(size_t i = 0; i < size_; ++i)
				{
					elements_[i] = other.elements_[i];
				}
			}
	};

}

