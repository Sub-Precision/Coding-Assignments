#lang racket

(require json
         racket/os)

;;; Returns a new grid with the specified move by the player.
;;; Used chat gpt to help me make this block of code
;;; as i am inexperienced with racket
;;; and python was giving me issues
(define (new-grid grid move player)
  (for/list ((col (in-list grid))
             (i (in-naturals)))
    (cond ((= i move)
           (define n (count zero? col))
           (when (= n 0)
             (error 'new-grid "Move ~a is illegal in column ~a" move i))
           (append (make-list (- n 1) 0) (list player) (drop col n)))
          (else col))))

;;; (winner? grid player) -> boolean?
;;;   grid : (listof (listof integer?))
;;;   player : exact-positive-integer?
;;; Returns true if the player has four pieces in a row, column, or diagonal.
(define (winner? grid player)
  ; Check rows
  (define (check-rows)
    (for/or ((row (in-list grid)))
      (for/or ((i (in-range (- (length row) 3))))
        (and (= player (list-ref row i))
             (= player (list-ref row (+ i 1)))
             (= player (list-ref row (+ i 2)))
             (= player (list-ref row (+ i 3)))))))

  ; Check columns
  (define (check-columns)
    (for/or ((i (in-range (length (car grid)))))
      (for/or ((j (in-range (- (length grid) 3))))
        (and (= player (list-ref (list-ref grid (+ j 0)) i))
             (= player (list-ref (list-ref grid (+ j 1)) i))
             (= player (list-ref (list-ref grid (+ j 2)) i))
             (= player (list-ref (list-ref grid (+ j 3)) i))))))

  ; Check diagonals
  (define (check-diagonals)
    (for/or ((i (in-range (- (length (car grid)) 3)))
             (j (in-range (- (length grid) 3))))
      (and (= player (list-ref (list-ref grid (+ j 0)) (+ i 0)))
           (= player (list-ref (list-ref grid (+ j 1)) (+ i 1)))
           (= player (list-ref (list-ref grid (+ j 2)) (+ i 2)))
           (= player (list-ref (list-ref grid (+ j 3)) (+ i 3))))))

  (or (check-rows) (check-columns) (check-diagonals)))


;;; This block will check if my program can win
;;; then prioritizing picking that move first
(define (winning-move? grid move player)
  (let ((next-grid (new-grid grid move player)))
    (winner? next-grid player)))

;;; This block is designed to analyze and see if the opponent can win on their next turn
;;; and if so, prevent that from happening by blocking it
;;; But the program prioritizes winning over blocking the opponent
(define (blocking-move? grid move player)
  (let ((next-grid (new-grid grid move (if (= player 1) 2 1))))
    (winning-move? next-grid move (if (= player 1) 2 1))))

;;; Returns a list of the valid moves considering the rules.
;;; As well as initializing the previous logic
;;; if my program cant win on it's turn AND the opponent can't win on it's next turn
;;; the program will simply pick the first option
(define (valid-moves precept)
  (match precept
    ((hash-table ('player player) ('height height) ('width width) ('grid grid))
     (define winning-move (find-winning-move grid player))
     (define blocking-move (find-blocking-move grid player))
     (define moves (valid-moves-for-column grid))
     (cond ((not (false? winning-move))
            (list winning-move)) ; Choose winning move if available
           ((not (false? blocking-move))
            (list blocking-move)) ; Choose blocking move if available
           ((not (null? moves))
            (list (first moves))) ; Choose the first available move
           (else
            moves)))))

;;; This block searches for a winning move
(define (find-winning-move grid player)
  (define moves (valid-moves-for-column grid))
  (for/or ((move (in-list moves)))
    (winning-move? grid move player)))

;;; Finds a move that blocks the opponent from winning on their next turn.
(define (find-blocking-move grid player)
  (define moves (valid-moves-for-column grid))
  (for/or ((move (in-list moves)))
    (blocking-move? grid move player)))

;;; Returns valid moves for a column (excluding full columns).
(define (valid-moves-for-column grid)
  (for/fold ((moves '()))
            ((col (in-range (length (first grid)))))
    (if (zero? (length (list-ref grid col)))
        (cons col moves)
        moves)))

;;; (main) -> void?
(define (main)
  (displayln "Connect Four" (current-error-port))
  ;; Process the precepts.
  (for ((json (in-lines)))
    (displayln json (current-error-port))
    (with-handlers ((exn:fail?
                     (lambda (e) (displayln "null"))))
      (define precept (string->jsexpr json))
      ;; Find the valid moves.
      (define moves (valid-moves precept))
      ;; Choose the move based on priorities: winning, blocking, first available.
      (define move
        (cond ((not (null? (first moves))) (first moves)) ; Winning move
              ((not (null? (second moves))) (second moves)) ; Blocking move
              (else (third moves)))) ; First available move
      ;; Return the action.
      (define action
        (hasheq 'move move))
      (define action-json (jsexpr->string action))
      (displayln action-json (current-error-port))
      (displayln action-json)
      (flush-output))))

;;; Start the program.
(main)
