#ifndef RBBST_H
#define RBBST_H

#include "bst.h"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

struct KeyError {};

/**
 * A special kind of node for an AVL tree, which adds the balance as a data
 * member, plus other additional helper functions. You do NOT need to implement
 * any functionality or add additional data members or helper functions.
 */
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value> {
public:
  // Constructor/destructor.
  AVLNode(const Key &key, const Value &value,
          std::shared_ptr<AVLNode<Key, Value>> parent);
  virtual ~AVLNode();

  // Getter/setter for the node's height.
  char getBalance() const;
  void setBalance(char balance);
  void updateBalance(char diff);

  std::shared_ptr<AVLNode<Key, Value>> getParent_AVL() const;
  std::shared_ptr<AVLNode<Key, Value>> getLeft_AVL() const;
  std::shared_ptr<AVLNode<Key, Value>> getRight_AVL() const;

protected:
  // to store the balance of a given node
  char balance_;
};

// -------------------------------------------------
// Begin implementations for the AVLNode class.
// -------------------------------------------------

// An explicit constructor to initialize the elements by calling the base class
// constructor and setting the color to red since every new node will be red
// when it is first inserted.

template <class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key &key, const Value &value,
                             std::shared_ptr<AVLNode<Key, Value>> parent)
    : Node<Key, Value>(key, value, parent), balance_(0) {}

// A destructor which does nothing.
template <class Key, class Value> AVLNode<Key, Value>::~AVLNode() {}

// A getter for the balance of a AVLNode.
template <class Key, class Value> char AVLNode<Key, Value>::getBalance() const {
  return balance_;
}

// A setter for the balance of a AVLNode.
template <class Key, class Value>
void AVLNode<Key, Value>::setBalance(char balance) {
  balance_ = balance;
}

// Adds diff to the balance of a AVLNode.
template <class Key, class Value>
void AVLNode<Key, Value>::updateBalance(char diff) {
  balance_ += diff;
}

// A separate getParent_AVL function other than the base class function due to
// covariant return types
template <class Key, class Value>
std::shared_ptr<AVLNode<Key, Value>>
AVLNode<Key, Value>::getParent_AVL() const {
  return std::static_pointer_cast<AVLNode<Key, Value>>(this->parent_);
}

// Similar getLeft_AVL function
template <class Key, class Value>
std::shared_ptr<AVLNode<Key, Value>> AVLNode<Key, Value>::getLeft_AVL() const {
  return std::static_pointer_cast<AVLNode<Key, Value>>(this->left_);
}

// Similar getRight_AVL function
template <class Key, class Value>
std::shared_ptr<AVLNode<Key, Value>> AVLNode<Key, Value>::getRight_AVL() const {
  return std::static_pointer_cast<AVLNode<Key, Value>>(this->right_);
}

// -----------------------------------------------
// End implementations for the AVLNode class.
// -----------------------------------------------

template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value> {
public:
  void rotateLeft(std::shared_ptr<AVLNode<Key, Value>> p,
                  std::shared_ptr<AVLNode<Key, Value>> n); // TODO
  void rotateRight(std::shared_ptr<AVLNode<Key, Value>> p,
                   std::shared_ptr<AVLNode<Key, Value>> n); // TODO

  // Remember, AVL is a self-balancing BST
  // Resultant tree after the insert and remove function should be a balanced
  // tree Make appropriate calls to rotateLeft(...) and rotateRight(...) in
  // insert and remove for balancing the height of the AVLTree
  virtual void insert(const std::pair<const Key, Value> &new_item); // TODO
  virtual void remove(const Key &key);                              // TODO
  void insertFix(std::shared_ptr<AVLNode<Key, Value>> p,
                 std::shared_ptr<AVLNode<Key, Value>> n);
  void removeFix(std::shared_ptr<AVLNode<Key, Value>> n, char diff);

protected:
  // Helper function already provided to you.
  virtual void nodeSwap(std::shared_ptr<AVLNode<Key, Value>> n1,
                        std::shared_ptr<AVLNode<Key, Value>> n2);

  // Add helper functions here
  // Consider adding functions like getBalance(...) given a key in the Tree
  // setBalance(...) given a key to a node and balance value, etc

  // You may implement a printRootAVL(...)
  // using the printRoot() function from the BST implementation
};

// Pre condition: p is the parent of n
// Post condition: p is the left child of n
template <class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(std::shared_ptr<AVLNode<Key, Value>> p,
                                     std::shared_ptr<AVLNode<Key, Value>> n) {
  // Check if p has parent, "gp", (!= nullptr); if so, find out if p is
  // left|right child of gp.
  if (p->getParent_AVL() != nullptr) {
    std::shared_ptr<AVLNode<Key, Value>> gp = p->getParent_AVL();
    if (gp->getKey() > p->getKey()) {
      // then update gp to point at n, and n to gp.
      gp->setLeft(n);
      n->setParent(gp);
    } else {
      // then update gp to point at n, and n to gp.
      gp->setRight(n);
      n->setParent(gp);
    }
  } else { // no parent
    n->setParent(nullptr);
  }

  // if n has left child, set p right child to point at lc. update lc parent to
  // p
  if (n->getLeft_AVL() != nullptr) {
    p->setRight(n->getLeft_AVL());
    n->getLeft_AVL()->setParent(p);
  } else {
    p->setRight(nullptr);
  }

  // then update n left child to p, p parent to n
  n->setLeft(p);
  p->setParent(n);

  // if rotation involved root, then update.
  if (this->root_->getKey() == p->getKey())
    this->root_ = n;
}

// Pre condition: p is the parent of n
// Post condition: p is the right child of n
template <class Key, class Value>
void AVLTree<Key, Value>::rotateRight(std::shared_ptr<AVLNode<Key, Value>> p,
                                      std::shared_ptr<AVLNode<Key, Value>> n) {
  // Check if p has parent, "gp", (!= nullptr); if so, find out if p is
  // left|right child of gp. then update gp to point at n, and n to gp. set p
  // parent to n. if n has left child, set p right child to point at rc. update
  // rc parent to p. then update n left child to p.

  // Check if p has parent, "gp", (!= nullptr); if so, find out if p is
  // left|right child of gp.
  if (p->getParent_AVL() != nullptr) {
    std::shared_ptr<AVLNode<Key, Value>> gp = p->getParent_AVL();
    if (gp->getKey() > p->getKey()) {
      // then update gp to point at n, and n to gp.
      gp->setLeft(n);
      n->setParent(gp);
    } else {
      // then update gp to point at n, and n to gp.
      gp->setRight(n);
      n->setParent(gp);
    }
  } else { // no parent
    n->setParent(nullptr);
  }

  // if n has right child, set p left child to point at rc. update rc parent to
  // p
  if (n->getRight_AVL() != nullptr) {
    p->setLeft(n->getRight_AVL());
    n->getRight_AVL()->setParent(p);
  } else {
    p->setLeft(nullptr);
  }

  // then update n left child to p, p parent to n
  n->setRight(p);
  p->setParent(n);

  // if rotation involved root, then update.
  if (this->root_->getKey() == p->getKey())
    this->root_ = n;
}

template <class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item) {
  // if tree is empty make root node
  if (this->empty()) {
    this->root_ = std::make_shared<AVLNode<Key, Value>>(
        new_item.first, new_item.second, nullptr);
    return;
  }

  // Once insert location is found, cur_node will be assigned updated parent
  std::shared_ptr<AVLNode<Key, Value>> parent =
      std::static_pointer_cast<AVLNode<Key, Value>>(this->root_);
  std::shared_ptr<AVLNode<Key, Value>> cur_node =
      std::static_pointer_cast<AVLNode<Key, Value>>(this->root_);
  bool is_left;

  while (1) {

    // node has found place on tree. update parent and child to point to each
    // other
    if (cur_node == nullptr) {
      // determine and set child
      cur_node = std::make_shared<AVLNode<Key, Value>>(new_item.first,
                                                       new_item.second, parent);
      char bal = parent->getBalance();
      if (is_left) {
        parent->setLeft(cur_node);
        bal--;
        parent->setBalance(bal);
        if (bal == -1) {
          insertFix(parent, parent->getLeft_AVL());
        }
      } else {
        parent->setRight(cur_node);
        bal++;
        parent->setBalance(bal);
        if (bal == 1) {
          insertFix(parent, parent->getRight_AVL());
        }
      }
      return;
    }

    // less-than, go left
    else if (new_item.first < cur_node->getKey()) {
      parent = cur_node;
      cur_node = cur_node->getLeft_AVL();
      is_left = true;
      continue;
    }
    // greater-than, go right
    else if (new_item.first > cur_node->getKey()) {
      parent = cur_node;
      cur_node = cur_node->getRight_AVL();
      is_left = false;
      continue;
    }
    // equal, overwrite
    else if (new_item.first == cur_node->getKey()) {
      cur_node->setValue(new_item.second);
      return;
    }
  }
}

template <class Key, class Value>
void AVLTree<Key, Value>::insertFix(std::shared_ptr<AVLNode<Key, Value>> p,
                                    std::shared_ptr<AVLNode<Key, Value>> n) {
  if (p == nullptr || p->getParent_AVL() == nullptr)
    return;
  //    std::shared_ptr<AVLNode<Key, Value>>  gp =
  //    std::static_pointer_cast<AVLNode<Key,Value>>(p->getParent_AVL());
  std::shared_ptr<AVLNode<Key, Value>> gp = p->getParent_AVL();
  //    this->printRoot(this->root_);

  char bal = gp->getBalance();
  //  p is left child of gp
  if (p == gp->getLeft_AVL()) {
    bal--;
    gp->setBalance(bal);
    if (gp->getBalance() == 0) {
      return;
    } else if (gp->getBalance() == -1) {
      // recurse up ancestor chain
      insertFix(gp, p);
    } else if (gp->getBalance() == -2) {
      // check for zig zig
      if (p->getBalance() == -1) {
        rotateRight(gp, p);
        gp->setBalance('0');
        p->setBalance('0');
      } else { // zig-zag
        std::shared_ptr<AVLNode<Key, Value>> n = p->getRight_AVL();
        rotateLeft(p, n);
        rotateRight(gp, n);

        // handle balance updates for 3 subcases:
        if (n->getBalance() == -1) { // case 1
          gp->setBalance(1);
          p->setBalance(0);
          n->setBalance(0);
        } else if (n->getBalance() == 0) { // case 2
          gp->setBalance(0);
          p->setBalance(0);
          n->setBalance(0);
        } else if (n->getBalance() == 1) { // case 3
          gp->setBalance(0);
          p->setBalance(0);
          n->setBalance(-1);
        }
      }
    }

    //  p is right child of gp
  } else {
    bal = gp->getBalance();
    bal++;
    gp->setBalance(bal);
    if (gp->getBalance() == 0) {
      return;
    } else if (gp->getBalance() == 1) {
      // recurse up ancestor chain
      insertFix(gp, p);
    } else if (gp->getBalance() == 2) {
      // check for zig zig
      if (p->getBalance() == 1) {
        rotateLeft(gp, p);
        gp->setBalance('0');
        p->setBalance('0');
      } else { // zig-zag
        std::shared_ptr<AVLNode<Key, Value>> n = p->getLeft_AVL();
        rotateRight(p, n);
        rotateLeft(gp, n);

        // handle balance updates for 3 subcases:
        if (n->getBalance() == -1) { // case 1
          gp->setBalance(-1);
          p->setBalance(0);
          n->setBalance(0);
        } else if (n->getBalance() == 0) { // case 2
          gp->setBalance(0);
          p->setBalance(0);
          n->setBalance(0);
        } else if (n->getBalance() == 1) { // case 3
          gp->setBalance(0);
          p->setBalance(0);
          n->setBalance(-1);
        }
      }
    }
  }
  //    this->printRoot(this->root_);
}
template <class Key, class Value>
void AVLTree<Key, Value>::remove(const Key &key) {
  // if tree is empty, do nothing
  if (this->empty())
    return;

  char diff;
  std::shared_ptr<AVLNode<Key, Value>> rf_parent;
  // attempt to find node
  std::shared_ptr<AVLNode<Key, Value>> to_remove =
      std::static_pointer_cast<AVLNode<Key, Value>>(this->internalFind(key));

  // nothing found
  if (to_remove == nullptr)
    return;

  // remove case 1: root node w/ no children
  if (to_remove->getLeft_AVL() == nullptr &&
      to_remove->getRight_AVL() == nullptr &&
      to_remove->getParent_AVL() == nullptr) {
    this->root_ = nullptr;
  }
  // remove case 2: leaf node
  else if (to_remove->getLeft_AVL() == nullptr &&
           to_remove->getRight_AVL() == nullptr) {
    std::shared_ptr<AVLNode<Key, Value>> parent = to_remove->getParent_AVL();
    if (parent != nullptr) {
      if (to_remove->getKey() < parent->getKey()) {
        parent->setLeft(nullptr);
        rf_parent = parent;
        diff = 1;
      } else {
        parent->setRight(nullptr);
        rf_parent = parent;
        diff = -1;
      }
    }
  }

  // remove case 3: node has children, swap w/ predecessor, then delete as leaf
  // (if no left child!) if left child, then have parent right point to left
  // child
  else if (to_remove->getLeft_AVL() != nullptr &&
           to_remove->getRight_AVL() != nullptr) {
    std::shared_ptr<AVLNode<Key, Value>> pred =
        std::static_pointer_cast<AVLNode<Key, Value>>(
            this->predecessor(to_remove));
    this->nodeSwap(to_remove, pred);

    // sub-case 1 : after swap, to remove has left child. Point parent to child
    // and child to parent sub-case 2 : remove parent pointer to leaf and reset
    // remove ptr
    std::shared_ptr<AVLNode<Key, Value>> parent = to_remove->getParent_AVL();
    if (parent->getLeft_AVL() == to_remove) {
      if (to_remove->getLeft_AVL() != nullptr) {
        parent->setLeft(to_remove->getLeft_AVL());
        parent->getLeft_AVL()->setParent(parent);
        rf_parent = parent;
        diff = -1;
      } else {
        // remove as leaf
        parent->setLeft(nullptr);
        rf_parent = parent;
        diff = 1;
      }
    } else {
      // if remove node is not leaf, and has left child, point parent right to
      // left child
      if (to_remove->getLeft_AVL() != nullptr) {
        parent->setRight(to_remove->getLeft_AVL());
        parent->getRight_AVL()->setParent(parent);
        rf_parent = parent;
        diff = -1;
      } else {
        parent->setRight(nullptr);
        rf_parent = parent;
        diff = -1;
      }
    }
  }

  // remove case 4: node has a child, promote child and delete
  else if (to_remove->getLeft_AVL() != nullptr ||
           to_remove->getRight_AVL() != nullptr) {
    std::shared_ptr<AVLNode<Key, Value>> child = to_remove;

    // promote child to removal node position
    if (to_remove->getLeft_AVL() != nullptr) {
      child = to_remove->getLeft_AVL();
      this->nodeSwap(to_remove, child);
    } else {
      child = to_remove->getRight_AVL();
      this->nodeSwap(to_remove, child);
    }

    // point child back to its children and reset to_remove pointer
    if (to_remove->getLeft_AVL() != nullptr) {
      child->setLeft(to_remove->getLeft_AVL());
      child->getLeft_AVL()->setParent(child);
      rf_parent = child;
      diff = 1;
    } else {
      child->setLeft(nullptr);
      rf_parent = child;
      diff = 1;
    }
    if (to_remove->getRight_AVL() != nullptr) {
      child->setRight(to_remove->getRight_AVL());
      child->getRight_AVL()->setParent(child);
      rf_parent = child;
      diff = -1;
    } else {
      child->setRight(nullptr);
      rf_parent = child;
      diff = -1;
    }
  }
  to_remove.reset();

  if (diff == 1 || diff == -1)
    removeFix(rf_parent, diff);
}

template <class Key, class Value>
void AVLTree<Key, Value>::removeFix(std::shared_ptr<AVLNode<Key, Value>> n,
                                    char diff) {

  // base case
  if (n == nullptr)
    return;

  std::shared_ptr<AVLNode<Key, Value>> p = n->getParent_AVL();
  char ndiff;
  if (p != nullptr) {
    if (p->getLeft_AVL() == n)
      ndiff = 1;
    else
      ndiff = -1;
  } else
    ndiff = -1;

  // right side removal
  if (ndiff == -1) {

    std::shared_ptr<AVLNode<Key, Value>> tall_child = n->getLeft_AVL();

    // Case 1
    if (diff == -1) {

      if (tall_child->getBalance() == -1) { // zig-zig
        n->setBalance(0);
        tall_child->setBalance(0);
        rotateRight(n, tall_child);
      } else if (tall_child->getBalance() == 0) { // zig-zig
        n->setBalance(-1);
        tall_child->setBalance(1);
        rotateRight(n, tall_child);
      } else if (tall_child->getBalance() == 1) { // zig-zag
        std::shared_ptr<AVLNode<Key, Value>> tc_rc = tall_child->getRight_AVL();
        rotateLeft(tc_rc, tc_rc->getRight_AVL());
        rotateRight(n, tc_rc);

        // update balances
        if (tc_rc->getBalance() == 1) {
          n->setBalance(-1);
          tall_child->setBalance(0);
          tc_rc->setBalance(0);
        } else if (tc_rc->getBalance() == 0) {
          n->setBalance(0);
          tall_child->setBalance(0);
          tc_rc->setBalance(0);
        } else if (tc_rc->getBalance() == -1) {
          n->setBalance(1);
          tall_child->setBalance(0);
          tc_rc->setBalance(0);
        }
        removeFix(p, ndiff);
      }
      return;
    }

    // Case 2
    else if (diff == 0) {
      return;
    }
    // Case 3
    else if (diff == 1) {
      removeFix(p, ndiff);
    }
  }
  // left side removal
  if (ndiff == 1) {

    std::shared_ptr<AVLNode<Key, Value>> tall_child = n->getRight_AVL();

    // Case 1
    if (diff == 1) {

      if (tall_child->getBalance() == 1) { // zig-zig
        n->setBalance(0);
        tall_child->setBalance(0);
        rotateLeft(n, tall_child);
      } else if (tall_child->getBalance() == 0) { // zig-zig
        n->setBalance(-1);
        tall_child->setBalance(1);
        rotateLeft(n, tall_child);
      } else if (tall_child->getBalance() == 1) { // zig-zag
        std::shared_ptr<AVLNode<Key, Value>> tc_lc = tall_child->getLeft_AVL();
        rotateRight(tc_lc, tc_lc->getRight_AVL());
        rotateLeft(n, tc_lc);

        // update balances
        if (tc_lc->getBalance() == 1) {
          n->setBalance(1);
          tall_child->setBalance(0);
          tc_lc->setBalance(0);
        } else if (tc_lc->getBalance() == 0) {
          n->setBalance(0);
          tall_child->setBalance(0);
          tc_lc->setBalance(0);
        } else if (tc_lc->getBalance() == -1) {
          n->setBalance(-1);
          tall_child->setBalance(0);
          tc_lc->setBalance(0);
        }
        removeFix(p, ndiff);
      }
      return;
    }
    // Case 2
    else if (diff == 0) {
      return;
    }
    // Case 3
    else if (diff == -1) {
      removeFix(p, ndiff);
    }
  }
}

// Function already completed for you
template <class Key, class Value>
void AVLTree<Key, Value>::nodeSwap(std::shared_ptr<AVLNode<Key, Value>> n1,
                                   std::shared_ptr<AVLNode<Key, Value>> n2) {
  BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
  char tempB = n1->getBalance();
  n1->setBalance(n2->getBalance());
  n2->setBalance(tempB);
}

#endif
