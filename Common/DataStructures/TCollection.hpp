#pragma once

/**
* @file   TCollection.hpp
* @brief  Dear student, this file contains the definition of the TCollection class template, which serves as a base class for all collection types in the project.
*         You will create this as a template class typeically holding "GetSize", "IsEmpty", and "Clear" methods, which are common to all collections.
*         Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

// Add your template here:
template <typename T>
class TCollection {
public:
    virtual ~TCollection() = default;
    
    virtual int  GetSize() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual void Clear() = 0;
};