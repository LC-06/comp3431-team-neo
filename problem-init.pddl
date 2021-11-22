(define (problem moveitemtoroom)
  (:domain turtlebot3-domain)
  (:objects
    turtlebot - robot
 initial-room - room
    living-room - room
    kitchen - room
    snickers grape  - item
  )

  (:init
    (at turtlebot initial-room)
    (in grape kitchen)
    (in snickers living-room)
    (hand_empty turtlebot)
  )

