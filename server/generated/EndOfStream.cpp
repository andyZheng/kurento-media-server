/* Autogenerated with Kurento Idl */

#include "EndOfStream.hpp"
#include <JsonSerializer.hpp>

void
Serialize(kurento::EndOfStream& event, JsonSerializer& s)
{
  try {
    kurento::Media &parent = dynamic_cast<kurento::Media&> (event);

    Serialize(parent, s);
  } catch (std::bad_cast) {

  }
}