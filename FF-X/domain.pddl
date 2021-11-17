(define (domain turtlebot3-domain)

  (:types
    room robot item
  )

  (:predicates
    (at ?rbt - robot ?rm - room)
    (in ?itm - item ?rm - room)
    (holding ?rbt - robot ?itm - item)
    (hand_empty ?rbt - robot)
  )

  (:action move
    :parameters (?rbt - robot ?from - room ?to - room)
    :precondition (at ?rbt ?from) 
    :effect (and (at ?rbt ?to) (not (at ?rbt ?from)))
  )

  (:action pick
    :parameters(?rbt - robot ?rm - room ?itm - item)
    :precondition (and (at ?rbt ?rm) 
    			(in ?itm ?rm) 
    			(hand_empty ?rbt)
    			(not (holding ?rbt ?itm)) )
    :effect (and (at ?rbt ?rm) (holding ?rbt ?itm) (not (hand_empty ?rbt))) 
  )

  (:action place
    :parameters(?rbt - robot ?rm - room ?itm - item)
    :precondition (and (at ?rbt ?rm) (not (hand_empty ?rbt)) (holding ?rbt ?itm))
    :effect (and (at ?rbt ?rm) (hand_empty ?rbt) (in ?itm ?rm) (not (holding ?rbt ?itm)))
  )
)
