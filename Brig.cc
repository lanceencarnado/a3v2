#include "Brig.h"

Brig::Brig() { }

/*   Function:  addPirate	                         		    */
/*         in:  Location of pirate to be added to the brig		*/
/*    Purpose:  Adds a single pirate to the brig in a cell		*/
/*				that has enough space for it					*/

int Brig::addPirate(Pirate* pirate)
{
    Cell* newCell;
    int index = -1;
    int rc;

    for (int i=0; i<cells.getSize(); ++i) {
        if (cells.get(i)->fits(pirate)) 
            index = i;
    }

    if (index >= 0) {
        rc = cells.get(index)->getPirates().push(pirate);
        if (rc != C_OK)
            return C_NOK;
        cells.get(index)->reduceSpace(pirate->getSpace());
    }
    else {
        newCell = new Cell;
        cells.add(newCell);
        rc = newCell->getPirates().push(pirate);
        if (rc != C_OK)
            return C_NOK;
        newCell->reduceSpace(pirate->getSpace());
    }
    return C_OK;
}

/*   Function:  addPirate	                         		    */
/*         in:  ID of pirate to be removed from the brig		*/
/*    Purpose:  Removes a pirate with a matching ID from the    */
/*              brig                                            */

int Brig::removePirate(int pirateId) {
    Cell* currCell;
    for (int i=0; i<cells.getSize(); ++i) {
        currCell = cells.get(i);
        // goes through each Queue and asks if it contains the Pirate to be removed
        if (currCell->getPirates().contains(pirateId)) {
            currCell->increaseSpace(currCell->getPirates().getPirateSpace(pirateId));
            currCell->getPirates().remove(pirateId);  // remove it from the Queue
            return C_OK;
        } 
    }
    return C_NOK;   // if we've reached this then the Pirate wasn't found
}

CArray& Brig::getCells() { return cells; }

/*   Function:  cleanup	                         		        */
/*    Purpose:  Calls deleteData() on each queue in the brig    */

void Brig::cleanup() {
	for (int i=0; i<cells.getSize(); ++i) {
		cells.get(i)->getPirates().deleteData();
	}
}

